#include "../headers/calc_average_score_students.h"

void c_a_s_s(std::ifstream& fin) {
    StudentSurnameRecord person{};
    A_s_students temp_person{};
    std::ofstream bi_out("src_files/st_average_score.bin", std::ios::binary);
    float temp{};
    float avg_score{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person))) {
        temp = 0;
        strcpy(temp_person.surname, person.surname);
        strcpy(temp_person.group, person.group);
        strcpy(temp_person.record_book_number, person.record_book_number);
        temp = (float)((person.grade[0] + person.grade[1] + person.grade[2]) / 3.0);//вычисление среднего балла студенов
        avg_score = static_cast<float>(std::round(temp * 10.0) / 10.0);//округление до 1 знака
        temp_person.av_score = avg_score;
        bi_out.write((char*)&temp_person, sizeof(temp_person));
    }
    bi_out.close();
    fin.close();
    std::cout << "\nDone! Average score of students is calculated!\n";
}

void calc_average_score_of_students(){
    std::ifstream bi_fin("src_files/surname_grades.bin", std::ios::binary);
    is_open(bi_fin);
    c_a_s_s(bi_fin);
}
