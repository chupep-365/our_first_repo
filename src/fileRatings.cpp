// Задание а) бинарный файл с оценками
#include "../headers/fileRatings.h"

struct StudentRecord
{
    char group[10];
    char record_book_number[10];
    char subject[3][10]; // 3 строки по 10 символов
    int16_t grade[3];
};

void create_bin_grates()
{
    std::cout << "Creating file..." << '\n';
    std::ifstream txtfile("src_files/students_grades.txt");
    std::ofstream binfile("src_files/st_grades.bin", std::ios::binary);
    if (!txtfile.is_open() || !binfile.is_open())
    {
        throw "Error opening files\n";
    }
    StudentRecord record{};
    std::string line;
    std::string delims = ";";
    size_t beg{}, end{};
    while (std::getline(txtfile, line)) // читает строку и кладет в line
    {
        if (line.empty())
        {
            continue;
        }
        beg = line.find_first_not_of(delims);
        if (beg == std::string::npos)
        {
            continue;
        }
        end = line.find_first_of(delims, beg);
        strcpy(record.group, line.substr(beg, end - beg).c_str());

        beg = line.find_first_not_of(delims, end);
        end = line.find_first_of(delims, beg);
        strcpy(record.record_book_number, line.substr(beg, end - beg).c_str());

        for (int16_t i = 0; i < 3; ++i)
        {
            beg = line.find_first_not_of(delims, end);
            end = line.find_first_of(delims, beg);
            strcpy(record.subject[i], line.substr(beg, end - beg).c_str());
            beg = line.find_first_not_of(delims, end);
            end = line.find_first_of(delims, beg);
            record.grade[i] = std::stoi(line.substr(beg, end - beg));
        }
        binfile.write(reinterpret_cast<const char *>(&record), sizeof(record));
    }
    txtfile.close();
    binfile.close();
    std::cout << "Done! Created st_grades.bin" << '\n';
}
void read_bin()
{
    std::ifstream fin("src_files/st_grades.bin");
    StudentRecord record;
    if (!fin.is_open())
    {
        throw "File wasn't open\n";
    }
    while (fin.read(reinterpret_cast<char *>(&record), sizeof(record)))
    {
        std::cout << record.group << ": " << record.record_book_number << "| ";
        for (int16_t i = 0; i < 3; ++i)
        {
            std::cout << record.subject[i] << ": " << record.grade[i] << "; ";
        }
        std::cout << '\n';
    }
    fin.close();
}
