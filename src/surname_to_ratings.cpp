// Задание б) фамилия + оценки
#include "../headers/fileRatings.h"
#include "../headers/file_to_bin.h"
#include "../headers/surname_to_ratings.h"

void surname_to_ratings()
{
    std::cout << "Creating file..." << '\n';
    std::ifstream names_binfile("src_files/st_info.bin", std::ios::binary);
    std::ifstream grades_binfile("src_files/st_grades.bin", std::ios::binary);
    std::ofstream names_grades_bin("src_files/surname_grades.bin", std::ios::binary);
    if (!names_binfile.is_open() || !names_grades_bin.is_open())
    {
        throw "Error opening files\n";
    }
    StudentRecord record;
    Student person{};
    while (grades_binfile.read(reinterpret_cast<char *>(&record), sizeof(record)))
    {
        StudentSurnameRecord result{};
        names_binfile.clear();                 // сбрасываем ошибку конца файла
        names_binfile.seekg(0, std::ios::beg); // ставим курсор для чтения в самое начало
        while (names_binfile.read(reinterpret_cast<char *>(&person), sizeof(person)))
        {
            if (std::strcmp(record.record_book_number, person.number) == 0)
            {
                std::strncpy(result.surname, person.surname, sizeof(result.surname) - 1); // фамилия
                break;
            }
        }
        std::strncpy(result.group, record.group, sizeof(result.group) - 1);                                        // группа
        std::strncpy(result.record_book_number, record.record_book_number, sizeof(result.record_book_number) - 1); // номер зачетки
        for (int16_t i = 0; i < 3; ++i)
        {
            std::strncpy(result.subject[i], record.subject[i], sizeof(result.subject[i]) - 1); // предмет и оценка
            result.grade[i] = record.grade[i];
        }
        names_grades_bin.write(reinterpret_cast<const char *>(&result), sizeof(result));
    }
    names_binfile.close();
    grades_binfile.close();
    names_grades_bin.close();
    std::cout << "Done! Created surname_grades.bin" << '\n';
}