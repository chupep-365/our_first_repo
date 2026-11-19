#include "../headers/calc_average_score_students.h"
#include "../headers/sort_list_undperf_st.h"
#include "../headers/grade_average_score_st.h"

void init(Smart_Average_array &s, size_t size)
{
    s.size = size;
    s.arr = new Grade_Average[size];
    s.top = 0;
    s.resize_factor = 1.67;
}

void resize(Smart_Average_array &s, size_t newsize)
{
    if (s.size == newsize)
    {
        return;
    }
    Grade_Average *newarr = new Grade_Average[newsize];
    for (int16_t i = 0; i < s.size; ++i)
    {
        newarr[i] = s.arr[i];
    }
    delete[] s.arr;
    s.arr = newarr;
    s.size = newsize;
}

void average_push(Smart_Average_array &s, const Grade_Average &element)
{
    if (s.size == s.top)
    {
        size_t newsize = (size_t)(s.size * s.resize_factor);
        resize(s, newsize);
    }
    s.arr[s.top++] = element;
}

bool sort_student_alph(const Grade_Average &student1, const Grade_Average &student2)
{
    return std::strcmp(student1.surname, student2.surname) < 0;
}

bool sort_students_av_score(const Grade_Average &student1, const Grade_Average &student2)
{
    return student1.av_score > student2.av_score;
}

void grade_av_score(const char *specified_group)
{
    std::cout << "Creating files..." << '\n';
    std::ifstream ifs("src_files/st_average_score.bin", std::ios::binary);
    std::ofstream ofs_alph_sort("src_files/grade_alph_sort.bin", std::ios::binary);
    std::ofstream ofs_av_score_sort("src_files/grade_av_score_sort.bin", std::ios::binary);
    if (!ifs.is_open() || !ofs_alph_sort.is_open() || !ofs_av_score_sort.is_open())
    {
        throw "Error opening files\n";
    }
    Smart_Average_array person{};
    A_s_students student{};
    init(person, 5);
    while (ifs.read(reinterpret_cast<char *>(&student), sizeof(student)))
    {
        if (std::strcmp(student.group, specified_group) == 0)
        {
            Grade_Average new_student{};
            std::strcpy(new_student.surname, student.surname);
            std::strcpy(new_student.record_book_number, student.record_book_number);
            new_student.av_score = student.av_score;
            average_push(person, new_student);
        }
    }
    std::sort(person.arr, person.arr + person.top, sort_student_alph); // сортируем по алфавиту
    ofs_alph_sort.write(reinterpret_cast<const char *>(person.arr), person.top * sizeof(Grade_Average));
    std::sort(person.arr, person.arr + person.top, sort_students_av_score); // сортируем по среднему баллу
    ofs_av_score_sort.write(reinterpret_cast<const char *>(person.arr), person.top * sizeof(Grade_Average));
    delete[] person.arr;
    ifs.close();
    ofs_alph_sort.close();
    ofs_av_score_sort.close();
    std::cout << "\nDone! Grade_average_scort_list.bin is ready.\n";
}
