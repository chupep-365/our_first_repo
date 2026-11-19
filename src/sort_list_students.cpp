// Задание е) сортировка списка неуспевающих и отличников
#include "../headers/sort_list_students.h"

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

void sorting(const char *inputpath, const char *outputpath)
{
    std::ifstream ifs(inputpath, std::ios::binary);
    if (!ifs.is_open())
    {
        throw "Error opening files\n";
    }
    std::ofstream ofs(outputpath, std::ios::binary);
    if (!ofs.is_open())
    {
        throw "Error opening files\n";
    }
    ifs.close();
    Smart_array<Key_info_students> student{};
    init(student, 5);
    Key_info_students bufer{};
    while (ifs.read(reinterpret_cast<char *>(&bufer), sizeof(bufer)))
    {
        push(student, bufer);
    }
    std::sort(student.arr, student.arr + student.top, compare_students);
    ofs.write(reinterpret_cast<const char *>(student.arr), student.top * sizeof(Key_info_students));
    ofs.close();
    delete_smart_array(student);
}

void sorted_list()
{
    std::cout << "Sorting files..." << '\n';
    sorting("src_files/list_of_underperforming_students.bin", "src_files/list_of_underperforming_students.bin");
    sorting("src_files/list_of_top_students.bin", "src_files/list_of_top_students.bin");
    std::cout << "Done! Top and underperformed students are sorted ";
}
