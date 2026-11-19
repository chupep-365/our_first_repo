#include "../headers/calc_average_score_students.h"
#include "../headers/grade_average_score_st.h"

bool sort_student_alph(const Grade_Average &student1, const Grade_Average &student2)
{
    return std::strcmp(student1.surname, student2.surname) < 0;
}

bool sort_students_av_score(const Grade_Average &student1, const Grade_Average &student2)
{
    return student1.av_score > student2.av_score;
}

void grade_av_score(int16_t specified_group)
{
    std::cout << "Creating files..." << '\n';
    std::ifstream ifs("src_files/st_average_score.bin", std::ios::binary);
    std::ofstream ofs_alph_sort("src_files/grade_alph_sort.bin", std::ios::binary);
    std::ofstream ofs_av_score_sort("src_files/grade_av_score_sort.bin", std::ios::binary);
    if (!ifs.is_open() || !ofs_alph_sort.is_open() || !ofs_av_score_sort.is_open())
    {
        throw "Error opening files\n";
    }
    Smart_array<Grade_Average> person{};
    A_s_students student{};
    init(person, 5);
    bool flag = true;
    while (ifs.read(reinterpret_cast<char *>(&student), sizeof(student)))
    {
        if (std::atoi(student.group) == specified_group)
        {
            Grade_Average new_student{};
            std::strcpy(new_student.surname, student.surname);
            std::strcpy(new_student.record_book_number, student.record_book_number);
            new_student.av_score = student.av_score;
            push(person, new_student);
            flag = false;
        }
    }
    if (flag == true)
    {
        throw "There isn't such group in list\n";
    }
    std::sort(person.arr, person.arr + person.top, sort_student_alph); // сортируем по алфавиту
    ofs_alph_sort.write(reinterpret_cast<const char *>(person.arr), person.top * sizeof(Grade_Average));
    std::sort(person.arr, person.arr + person.top, sort_students_av_score); // сортируем по среднему баллу
    ofs_av_score_sort.write(reinterpret_cast<const char *>(person.arr), person.top * sizeof(Grade_Average));
    delete_smart_array(person);
    ifs.close();
    ofs_alph_sort.close();
    ofs_av_score_sort.close();
    std::cout << "\nDone! Grade_average_scort_list.bin is ready.\n";
}

void ask_specific_group()
{
    int16_t group{};
    std::cout << "Enter the group of students" << '\n';
    std::cin >> group;
    grade_av_score(group);
}
