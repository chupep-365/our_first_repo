#include "generator.h"


void generate_students_info(const size_t students) {
    std::cout << "\nCreating files...\n";
    std::ofstream info_file("students_info.txt");
    std::ofstream grades_file("students_grades.txt");
    if(!info_file || !grades_file) {
        throw "\nError: cant create files\n";
    }
    const uint16_t group_count = get_groups_amount(students);
    if(group_count > UINT16_MAX) {
        throw "\nError: too many groups (try less students)\n";
    }
    const size_t number_width = std::max<size_t>(6, std::to_string(students).size());
    std::string number{};
    for(size_t i{0}; i < students; ++i) {
        const std::string number = get_number(i + 1, number_width);
        const char* surname = surnames[rand_int(0, surname_сount - 1)];
        const char* firstName = firstNames[rand_int(0, firstname_count - 1)];
        const char* patronymic = patronymics[rand_int(0, patronymic_count - 1)];
        const uint16_t group_number = rand_int(1, group_count);
        // НОМЕР ЗАЧЁТКИ;Фамилия;Имя;Отчество
        info_file << number << ';' << surname << ';' << firstName << ';' << patronymic << '\n';
        // ГРУППА;НОМЕР ЗАЧЁТКИ;МА;Оценка;ГЕО;Оценка;ПРОГ;Оценка
        grades_file << group_number << ';' << number << ";МА;" << rand_int(2, 10) << ";ГЕО;" << rand_int(2, 10)
                    << ";ПРОГ;" << rand_int(2, 10) << '\n';
    }
    info_file.close();
    grades_file.close();
    std::cout << "\nDone! created students_info.txt and students_grades.txt";
}

uint16_t rand_int(const uint16_t min, const uint16_t max) {
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<uint16_t> dstrb(min, max);
    return dstrb(gen);
}

std::string get_number(size_t number, size_t width) {
    std::string result = std::to_string(number);
    if(result.size() < width) {
        result.insert(0, width - result.size(), '0');
    }
    return result;
}

uint16_t get_groups_amount(size_t students) {
    const size_t amount = students / 30 + (students % 30 != 0);
    return std::max((size_t)1, amount);
}