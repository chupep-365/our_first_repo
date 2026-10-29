#pragma once

#include <fstream>
#include <iostream>
#include <cstdint>
#include <random>
#include <cmath>
#include <string>

// generates 2 .txt files according to the task: students_info.txt and students_grades.txt
void generate_students_info(const size_t);////////////////////////////////////////////////                        
//////////////////////////////////////////////////////////////////////////////////////////
uint16_t rand_int(const uint16_t, const uint16_t);
std::string get_number(size_t, size_t);
uint16_t get_groups_amount(size_t);

constexpr const char* surnames[] = {
    "Иванов", "Петров", "Сидоров", "Смирнов", "Соколовский",
    "Попов", "Васильев", "Соколов", "Михайлов", "Новиков",
    "Федоров", "Морозов", "Волков", "Алексеев", "Лебедев"
};
constexpr const char* firstNames[] = {
    "Александр", "Дмитрий", "Максим", "Иван", "Артём",
    "Михаил", "Никита", "Егор", "Афанасий", "Марк",
    "Евстафий", "Ольгерд", "Анатолий", "Даниил", "Святополк"
};
constexpr const char* patronymics[] = {
    "Александрович", "Дмитриевич", "Максимович", "Иванович",
    "Артёмович", "Михайлович", "Никитич", "Егорович",
    "Антонович", "Даниилович", "Иванович", "Маркович",
    "Сергеевич", "Андреевич", "Гвидонович"
};
constexpr uint16_t surname_сount = 15;
constexpr uint16_t firstname_count = 15;
constexpr uint16_t patronymic_count = 15;