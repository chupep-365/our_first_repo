// Задание е) сортировка списка неуспевающих и отличников
#include "../headers/sort_list_students.h"

template <class T>
void init(Smart_array<T> &s, size_t size)
{
    s.size = size;
    s.arr = new T[size];
    s.top = 0;
    s.resize_factor = 1.67;
}

bool compare_students(const Key_info_students &student1, const Key_info_students &student2)
{
    int16_t group1 = std::atoi(student1.group);
    int16_t group2 = std::atoi(student2.group);
    if (group1 != group2)
    {
        return group1 < group2;
    }
    return std::strcmp(student1.surname, student2.surname) < 0;
}

template <class T>
void resize(Smart_array<T> &s, size_t newsize)
{
    if (s.size == newsize)
    {
        return;
    }
    T *newarr = new T[newsize];
    for (int16_t i = 0; i < s.size; ++i)
    {
        newarr[i] = s.arr[i];
    }
    delete[] s.arr;
    s.arr = newarr;
    s.size = newsize;
}

template <class T>
void push(Smart_array<T> &s, const T &element)
{
    if (s.size == s.top)
    {
        size_t newsize = (size_t)(s.size * s.resize_factor);
        resize(s, newsize);
    }
    s.arr[s.top++] = element;
}
template <class T>
void delete_smart_array(Smart_array<T> &s)
{
    delete[] s.arr;
    s.arr = nullptr;
    s.size = 0;
    s.top = 0;
}

void sorting(const char *inputpath, const char *outputpath, int16_t specified_group)
{
    std::cout << "Creating file..." << '\n';
    std::ifstream ifs(inputpath, std::ios::binary);
    if (!ifs.is_open())
    {
        throw "Error opening files\n";
    }
    Smart_array<Key_info_students> student{};
    init(student, 5);
    Key_info_students bufer{};
    bool flag = true;
    while (ifs.read(reinterpret_cast<char *>(&bufer), sizeof(bufer)))
    {
        if (std::atoi(bufer.group) == specified_group)
        {
            push(student, bufer);
            flag = false;
        }
    }
    if (flag == true)
    {
        throw "There isn't such group in list\n";
    }
    std::sort(student.arr, student.arr + student.top, compare_students);
    std::ofstream ofs(outputpath, std::ios::binary);
    if (!ofs.is_open())
    {
        throw "Error opening files\n";
    }
    ofs.write(reinterpret_cast<const char *>(student.arr), student.top * sizeof(Key_info_students));
    ifs.close();
    ofs.close();
    delete_smart_array(student);
}

void sorted_list()
{
    int16_t group{};
    std::cout << "Enter the number of group" << '\n';
    std::cin >> group;
    sorting("src_files/list_of_underperforming_students.bin", "src_files/sort_group_underperf_students.bin", group);
    sorting("src_files/list_of_top_students.bin", "src_files/sort_group_top_students.bin", group);
    std::cout << "Done! Sorted list for group" << group << "is created" << '\n';
}
