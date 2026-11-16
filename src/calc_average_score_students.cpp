#include "../headers/calc_average_score_students.h"

struct Student{
    char surname[32];
    char group[8];
    char record_book_number[16];
    char subject[3][10]; // 3 строки по 10 символов
    int16_t grade[3];
};

struct A_s_students{
    char surname[32];
    char group[8];
    char record_book_number[16];
    float av_score;
};//структура для записи промежуточного результата

void is_empty(std::streamsize size){
    if(size <= 0){
        throw "\nFile is empty!\n";
    }
}//проверка на пустоту исходного бинарного файла

void c_a_s_s(std::ifstream& fin) {
    Student person;
    A_s_students temp_person;
    float temp{};
    std::ofstream bi_out("src_files/st_average_score.bin", std::ios::binary);
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person))) {
        strcpy(temp_person.surname, person.surname);
        strcpy(temp_person.group, person.group);
        strcpy(temp_person.record_book_number, person.record_book_number);
        temp = (person.grade[0] + person.grade[1] + person.grade[2]) / 3;//вычисление среднего балла студенов
        temp_person.av_score = temp;
        bi_out.write((char*)&temp_person, sizeof(temp_person));
    }
    bi_out.close();
    fin.close();
    std::cout << "\nDone! Average score of students is calculating.\n";
}

void calc_average_score_of_students(){
    std::ifstream bi_fin("src_files/surname_grades.bin", std::ios::binary | std::ios::ate);
    is_open(bi_fin);
    std::streamsize size = bi_fin.tellg();
    bi_fin.seekg(0, std::ios::beg);
    is_empty(size);
    c_a_s_s(bi_fin);
}
