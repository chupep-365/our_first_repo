// Задание а) бинарный файл с оценками
#include "../headers/fileRatings.h"
#include "../headers/surname_to_ratings.h"

void create_bin_grades()
{
    std::cout << "Creating file..." << '\n';
    std::ifstream txtfile("src_files/students_grades.txt");
    std::ofstream binfile("src_files/st_grades.bin", std::ios::binary);
    if (!txtfile.is_open() || !binfile.is_open())
    {
        throw "Error opening files\n";
    }
    std::string line{};
    std::string temp{};
    size_t beg{}, end{};
    while (std::getline(txtfile, line))
    {
        if (line.empty())
        {
            continue;
        }
        StudentRecord record{};
        beg = 0;
        end = line.find(';', beg);
        if (end == std::string::npos)
        {
            continue;
        }
        temp = line.substr(beg, end - beg);
        std::strncpy(record.group, temp.c_str(), sizeof(record.group) - 1);
        beg = end + 1;
        end = line.find(';', beg);
        if (end == std::string::npos)
        {
            continue;
        }
        temp = line.substr(beg, end - beg);
        std::strncpy(record.record_book_number, temp.c_str(), sizeof(record.record_book_number) - 1);
        bool is_valid = true;
        for (int16_t i = 0; i < 3; ++i)
        {
            beg = end + 1;
            end = line.find(';', beg);
            if (end == std::string::npos)
            {
                is_valid = false;
                break;
            }
            temp = line.substr(beg, end - beg);
            std::strncpy(record.subject[i], temp.c_str(), sizeof(record.subject[i]) - 1);
            beg = end + 1;
            if (i < 2)
            {
                end = line.find(';', beg);
                if (end == std::string::npos)
                {
                    is_valid = false;
                    break;
                }
                temp = line.substr(beg, end - beg);
            }
            else
            {
                temp = line.substr(beg);
            }
            record.grade[i] = static_cast<int16_t>(std::stoi(temp));
        }
        if (is_valid)
        {
            binfile.write(reinterpret_cast<const char *>(&record), sizeof(record));
        }
    }
    txtfile.close();
    binfile.close();
    std::cout << "Done! Created st_grades.bin" << '\n';
}
void read_bin()
{
    std::ifstream fin("src_files/surname_grades.bin", std::ios::binary);
    StudentSurnameRecord record;
    if (!fin.is_open())
    {
        throw "File wasn't open\n";
    }
    while (fin.read(reinterpret_cast<char *>(&record), sizeof(record)))
    {
        std::cout << record.surname << ": " << record.group << ": " << record.record_book_number << "| ";
        for (int16_t i = 0; i < 3; ++i)
        {
            std::cout << record.subject[i] << ": " << record.grade[i] << "; ";
        }
        std::cout << '\n';
    }
    fin.close();
}
