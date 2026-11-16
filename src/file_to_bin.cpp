#include "../headers/file_to_bin.h"

// zadanie a1

void is_open(std::ifstream &fin)
{
    if (!fin)
    {
        throw "\nError of open file!\n";
    }
} // proverka otkrytia

void f_to_b_i(std::ifstream &fin)
{
    std::string line{};
    std::string temp{};
    size_t beg{}, end{};
    std::ofstream bin_out("src_files/st_info.bin", std::ios::binary);
    while (std::getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }
        Student person{};
        // 1. номер зачетки
        beg = 0;
        end = line.find(';', beg);
        if (end == std::string::npos)
        {
            continue;
        }
        temp = line.substr(beg, end - beg);
        strncpy(person.number, temp.c_str(), sizeof(person.number) - 1);
        // 2. фамилия
        beg = end + 1;
        end = line.find(';', beg);
        if (end == std::string::npos)
        {
            continue;
        }
        temp = line.substr(beg, end - beg);
        strncpy(person.surname, temp.c_str(), sizeof(person.surname) - 1);
        // 3. имя
        beg = end + 1;
        end = line.find(';', beg);
        if (end == std::string::npos)
        {
            continue;
        }
        temp = line.substr(beg, end - beg);
        strncpy(person.name, temp.c_str(), sizeof(person.name) - 1);
        // 4. отчество
        beg = end + 1;
        temp = line.substr(beg);
        strncpy(person.fname, temp.c_str(), sizeof(person.fname) - 1);
        bin_out.write((char *)&person, sizeof(person));
    }
    bin_out.close();
    fin.close();
    std::cout << "\nDone! created st_info.bin\n";
}

void create_bin_info()
{
    std::ifstream fin("src_files/students_info.txt");
    is_open(fin);
    f_to_b_i(fin);
} // функция для выполнения задания а1
