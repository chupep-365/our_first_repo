#include "../headers/generator.h"
#include <cstring>

//zadanie a1

struct Student{
    char sourname[20];
    char name[20];
    char fname[20];
    char number[6];
};

void is_open(std::ifstream& fin){
    if(!fin){
        std::cout << "\nError\n";
    }
}//proverka otkrytia

void create_bin_info(std::ifstream& fin) {
    Student person;
    std::string delims{"; /.,"};
    std::getline(fin, delims);
    std::string temp{};
    std::string name{};
    size_t beg{}, end{};
    std::ofstream bin_out("src_files/st_info.bin", std::ios::binary);
    while(std::getline(fin, temp)){
        if(temp.empty()){
            continue;
        }
        beg = temp.find_first_not_of(delims);
        if(beg == std::string::npos){
            continue;
        }
        end = temp.find_first_of(delims, beg);
        if(end == std::string::npos){
            end = temp.length();
        }
        name = temp.substr(beg, end - beg);
        strcpy(person.number, name.c_str());//запись номера зачётки в структуру
        beg = temp.find_first_not_of(delims, end);
        if(beg == std::string::npos){
            continue;
        }
        end = temp.find_first_of(delims, beg);
        if(end == std::string::npos){
            end = temp.length();
        }
        name = temp.substr(beg, end - beg);
        strcpy(person.sourname, name.c_str());//запись фамилии в структуру
        beg = temp.find_first_not_of(delims, end);
        if(beg == std::string::npos){
            continue;
        }
        end = temp.find_first_of(delims, beg);
        if(end == std::string::npos){
            end = temp.length();
        }
        name = temp.substr(beg, end - beg);
        strcpy(person.name, name.c_str());//запись имени в структуру
        beg = temp.find_first_not_of(delims, end);
        if(beg == std::string::npos){
            continue;
        }
        end = temp.find_first_of(delims, beg);
        if(end == std::string::npos){
            end = temp.length();
        }
        name = temp.substr(beg, end - beg);
        strcpy(person.fname, name.c_str());//запись отчества в структуру
        bin_out.write((char*)&person, sizeof(person));//заполнения строчки в бинарный файл
        beg = 0;
        end = 0; 
    }
    bin_out.close();//закрытие потоков
    fin.close();
    std::cout << "\nDone! created st_info.bin\n";
}

void f_to_b_i(){
    std::ifstream fin("src_files/students_info.txt");
    is_open(fin);
    create_bin_info(fin);
}//функция для выполнения задания а1

