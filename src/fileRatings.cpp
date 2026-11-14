// Задание а) бинарный файл с оценками
#include "../headers/fileRatings.h"

struct Subject
{
    std::string name;
    int grade;
};
struct StudentRecord
{
    std::string group;
    std::string record_book_number;
    Subject subjects[3];
};

void conv_txt_to_bin(const std::string &filenametxt, const std::string &filenamebin)
{
    std::ifstream txtfile("src_files/students_grades.txt");
    std::ofstream binfile("src_files/students_grades.bin", std::ios::binary);
    if (!txtfile.is_open() || !binfile.is_open())
    {
        return;
    }
    std::string line;
    size_t number_line = 0;
    while (std::getline(txtfile, line)) // читает строку и кладет в line
    {
        if (line.empty())
        {
            continue;
        }
        ++number_line;
        size_t pos = 0;
        size_t next_pos;
        std::string array[50]; // массив для строк
        size_t counter = 0;
        while (pos < line.length() && counter < 50)
        {
            next_pos = line.find(';', pos);
            if (next_pos == std::string::npos)
            {
                array[counter] = line.substr(pos);
                counter++;
                break;
            }
            else
            {
                array[counter] = line.substr(pos, next_pos - pos);
                counter++;
                pos = next_pos + 1;
            }
        }
        StudentRecord record;
        record.group = array[0];
        record.record_book_number = array[1];
        for (int i = 0; i < 3; ++i) // идем по кол-ву предметов (3)
        {
            int subject_index = (i * 2) + 2;
            int grade_index = subject_index + 1;
            record.subjects[i].name = array[subject_index];
            record.subjects[i].grade = std::stoi(array[grade_index]);
        }

        size_t group_length = record.group.length();                                        // вычисляем длину строки
        binfile.write(reinterpret_cast<const char *>(&group_length), sizeof(group_length)); // номер группы
        if (group_length > 0)
        {
            binfile.write(record.group.data(), group_length);
        }
        size_t record_book_length = record.record_book_number.length();
        binfile.write(reinterpret_cast<const char *>(&record_book_length), sizeof(record_book_length)); // номер зачетки
        if (record_book_length > 0)
        {
            binfile.write(record.record_book_number.data(), record_book_length);
        }
        for (int i = 0; i < 3; ++i)
        {
            group_length = record.subjects[i].name.length();
            binfile.write(reinterpret_cast<const char *>(&group_length), sizeof(group_length));
            if (group_length > 0)
            {
                binfile.write(record.subjects[i].name.data(), group_length);
                binfile.write(reinterpret_cast<const char *>(&record.subjects[i].grade), sizeof(int));
            }
        }
    }
    txtfile.close();
    binfile.close();
}
