// Задание е) сортировка списка неуспевающих
#include "../headers/sort_list_undperf_st.h"

void init(Smart_array &s, size_t size)
{
    s.size = size;
    s.arr = new Key_info_students[size];
    s.top = 0;
    s.resize_factor = 1.67;
}

int16_t char_to_int(const char *group)
{
    return std::atoi(group);
}

bool compare_students(const Key_info_students &student1, const Key_info_students &student2)
{
    int16_t group1 = char_to_int(student1.group);
    int16_t group2 = char_to_int(student2.group);
    if (group1 != group2)
    {
        return group1 < group2;
    }
    return std::strcmp(student1.surname, student2.surname) < 0;
}

Key_info_students top(Smart_array &s)
{
    return s.arr[s.top - 1];
}

void resize(Smart_array &s, size_t newsize)
{
    if (s.size == newsize)
    {
        return;
    }
    Key_info_students *newarr = new Key_info_students[newsize];
    for (int16_t i = 0; i < s.size; ++i)
    {
        newarr[i] = s.arr[i];
    }
    delete[] s.arr;
    s.arr = newarr;
    s.size = newsize;
}

void push(Smart_array &s, const Key_info_students &element)
{
    if (s.size == s.top)
    {
        size_t newsize = (size_t)(s.size * s.resize_factor);
        resize(s, newsize);
    }
    s.arr[s.top++] = element;
}

void sort_list()
{
    std::cout << "Creating file..." << '\n';
    std::ifstream ifs("src_files/list_of_underperforming_students.bin", std::ios::binary);
    std::ofstream ofs("src_files/sort_list_undperf_st.bin", std::ios::binary);
    if (!ifs.is_open() || !ofs.is_open())
    {
        throw "Error opening files\n";
    }
    Smart_array student{};
    init(student, 5);
    Key_info_students bufer;
    while (ifs.read(reinterpret_cast<char *>(&bufer), sizeof(bufer)))
    {
        push(student, bufer);
    }
    std::sort(student.arr, student.arr + student.top, compare_students);
    ofs.write(reinterpret_cast<const char *>(student.arr), student.top * sizeof(Key_info_students));

    delete[] student.arr;
    ifs.close();
    ofs.close();
}
