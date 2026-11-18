#include "../headers/read_bin.h"

size_t amount(std::ifstream& fin, A_s_students person){
    size_t amount{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person))){
        ++amount;
    }
    fin.clear();
    fin.seekg(0, std::ios::beg);
    return amount;
}

size_t amount(std::ifstream& fin, Key_info_students person){
    size_t amount{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person))){
        ++amount;
    }
    fin.clear();
    fin.seekg(0, std::ios::beg);
    return amount;
}

size_t amount(std::ifstream& fin, Student person){
    size_t amount{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person))){
        ++amount;
    }
    fin.clear();
    fin.seekg(0, std::ios::beg);
    return amount;
}

size_t amount(std::ifstream& fin, StudentRecord person){
    size_t amount{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person))){
        ++amount;
    }
    fin.clear();
    fin.seekg(0, std::ios::beg);
    return amount;
}

size_t amount(std::ifstream& fin, StudentSurnameRecord person){
    size_t amount{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person))){
        ++amount;
    }
    fin.clear();
    fin.seekg(0, std::ios::beg);
    return amount;
}

void read_bin(std::ifstream& fin, A_s_students* persons, size_t amount_persons){
    A_s_students person{};
    size_t i{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person)) && i < amount_persons){
        strcpy(persons[i].surname, person.surname);
        strcpy(persons[i].group, person.group);
        strcpy(persons[i].record_book_number, person.record_book_number);
        persons[i].av_score = person.av_score;\
        ++i;
    }
    fin.close();
}

void read_bin(std::ifstream& fin, Key_info_students* persons, size_t amount_persons){
    Key_info_students person{};
    size_t i{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person)) && i < amount_persons){
        strcpy(persons[i].surname, person.surname);
        strcpy(persons[i].group, person.group);
        strcpy(persons[i].record_book_number, person.record_book_number);
        ++i;
    }
    fin.close();
}

void read_bin(std::ifstream& fin, Student* persons, size_t amount_persons){
    Student person{};
    size_t i{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person)) && i < amount_persons){
        strcpy(persons[i].surname, person.surname);
        strcpy(persons[i].name, person.name);
        strcpy(persons[i].fname, person.fname);
        strcpy(persons[i].number, person.number);
        ++i;
    }
    fin.close();
}

void read_bin(std::ifstream& fin, StudentRecord* persons, size_t amount_persons){
    StudentRecord person{};
    size_t i{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person)) && i < amount_persons){
        strcpy(persons[i].group, person.group);
        strcpy(persons[i].record_book_number, person.record_book_number);
        for(size_t j{}; j < 3; ++j){
            strcpy(persons[i].subject[j], person.subject[j]);
            persons[i].grade[j] = person.grade[j];
        }
        ++i;
    }
    fin.close();
}

void read_bin(std::ifstream& fin, StudentSurnameRecord* persons, size_t amount_persons){
    StudentSurnameRecord person{};
    size_t i{};
    while(fin.read(reinterpret_cast<char*>(&person), sizeof(person)) && i < amount_persons){
        strcpy(persons[i].surname, person.surname);
        strcpy(persons[i].group, person.group);
        strcpy(persons[i].record_book_number, person.record_book_number);
        for(size_t j{}; j < 3; ++j){
            strcpy(persons[i].subject[j], person.subject[j]);
            persons[i].grade[j] = person.grade[j];
        }
        ++i;
    }
    fin.close();
}

void bin_to_txt(A_s_students* persons, size_t amount_persons){
    std::ofstream fout("src_files/st_average_score.txt");
    for(size_t j{}; j < amount_persons; ++j){
        fout << persons[j].surname << "---" << persons[j].group << "---" << persons[j].record_book_number << ": " << persons[j].av_score << '\n';
    }
}

void bin_to_txt(Key_info_students* persons, size_t amount_persons){
    std::ofstream fout("src_files/list_of_st.txt");
    for(size_t j{}; j < amount_persons; ++j){
        fout << persons[j].surname << "---" << persons[j].group << "---" << persons[j].record_book_number << '\n';
    }
}

void bin_to_txt(Student* persons, size_t amount_persons){
    std::ofstream fout("src_files/students_info.txt");
    for(size_t j{}; j < amount_persons; ++j){
        fout << persons[j].surname << "---" << persons[j].name << "---" << persons[j].fname << "---" << persons[j].number << '\n';
    }
}

void bin_to_txt(StudentRecord* persons, size_t amount_persons){
    std::ofstream fout("src_files/st_grades.txt");
    for(size_t j{}; j < amount_persons; ++j){
        fout << persons[j].group << "---" << persons[j].record_book_number;
        for(size_t k{}; k < 3; ++k){
            fout << "---" << persons[j].subject[k] << "-" << persons[j].grade[k];
        }
        fout << '\n';
    }
}

void bin_to_txt(StudentSurnameRecord* persons, size_t amount_persons){
    std::ofstream fout("src_files/surname_grades.txt");
    for(size_t j{}; j < amount_persons; ++j){
        fout << persons[j].surname << "---" << persons[j].group << "---" << persons[j].record_book_number;
        for(size_t k{}; k < 3; ++k){
            fout << "---" << persons[j].subject[k] << "-" << persons[j].grade[k];
        }
        fout << '\n';
    }
}

void bin_to_con(A_s_students* persons, size_t amount_persons){
    for(size_t j{}; j < amount_persons; ++j){
        std::cout << persons[j].surname << "---" << persons[j].group << "---" << persons[j].record_book_number << ": " << persons[j].av_score << '\n';
    }
    std::cout << "\n\n";
}

void bin_to_con(Key_info_students* persons, size_t amount_persons){
    for(size_t j{}; j < amount_persons; ++j){
        std::cout << persons[j].surname << "---" << persons[j].group << "---" << persons[j].record_book_number << '\n';
    }
    std::cout << "\n\n";
}

void bin_to_con(Student* persons, size_t amount_persons){
    for(size_t j{}; j < amount_persons; ++j){
        std::cout << persons[j].surname << "---" << persons[j].name << "---" << persons[j].fname << "---" << persons[j].number << '\n';
    }
    std::cout << "\n\n";
}

void bin_to_con(StudentRecord* persons, size_t amount_persons){
    for(size_t j{}; j < amount_persons; ++j){
        std::cout << persons[j].group << "---" << persons[j].record_book_number;
        for(size_t k{}; k < 3; ++k){
            std::cout << "---" << persons[j].subject[k] << "-" << persons[j].grade[k];
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

void bin_to_con(StudentSurnameRecord* persons, size_t amount_persons){
    for(size_t j{}; j < amount_persons; ++j){
        std::cout << persons[j].surname << "---" << persons[j].group << "---" << persons[j].record_book_number;
        for(size_t k{}; k < 3; ++k){
            std::cout << "---" << persons[j].subject[k] << "-" << persons[j].grade[k];
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

void bin_to_f(){
    std::cout << "What do you want interpret?\n1. st_average_sore.bin;\n2. list_of_top_students.bin;\n3. list_of_underperforming_students.bin;\n4. st_info.bin;\n5. st_grades.bin;\n6. surname_grades.bin;\n";
    size_t num1{};
    size_t num2{};
    std::cin >> num1;
    std::cout << "Where?\n1. In console;\n2. In txt file;\n";
    std::cin >> num2;
    if(num1 == 1){
        std::ifstream biin1("src_files/st_average_score.bin", std::ios::binary);
        A_s_students person1{};
        size_t amount_st1 = amount(biin1, person1);
        A_s_students* persons1 = new A_s_students[amount_st1];
        read_bin(biin1, persons1, amount_st1);
        if(num2 == 1){
            bin_to_con(persons1, amount_st1);
        }
        if(num2 == 2){
            bin_to_txt(persons1, amount_st1);
        }
    } 
    else if(num1 == 2){
        std::ifstream biin2("src_files/list_of_top_students.bin", std::ios::binary);
        Key_info_students person2{};
        size_t amount_st2 = amount(biin2, person2);
        Key_info_students* persons2 = new Key_info_students[amount_st2];
        read_bin(biin2, persons2, amount_st2);
        if(num2 == 1){
            bin_to_con(persons2, amount_st2);
        }
        if(num2 == 2){
            bin_to_txt(persons2, amount_st2);
        }
    }
    else if(num1 == 3){
        std::ifstream biin3("src_files/list_of_underperforming_students.bin", std::ios::binary);
        Key_info_students person3{};
        size_t amount_st3 = amount(biin3, person3);
        Key_info_students* persons3 = new Key_info_students[amount_st3];
        read_bin(biin3, persons3, amount_st3);
        if(num2 == 1){
            bin_to_con(persons3, amount_st3);
        }
        if(num2 == 2){
            bin_to_txt(persons3, amount_st3);
        }
    }
    else if(num1 == 4){
        std::ifstream biin4("src_files/st_info.bin", std::ios::binary);
        Student person4{};
        size_t amount_st4 = amount(biin4, person4);
        Student* persons4 = new Student[amount_st4];
        read_bin(biin4, persons4, amount_st4);
        if(num2 == 1){
            bin_to_con(persons4, amount_st4);
        }
        if(num2 == 2){
            bin_to_txt(persons4, amount_st4);
        }
    }
    else if(num1 == 5){
        std::ifstream biin5("src_files/st_grades.bin", std::ios::binary);
        StudentRecord person5{};
        size_t amount_st5 = amount(biin5, person5);
        StudentRecord* persons5 = new StudentRecord[amount_st5];
        read_bin(biin5, persons5, amount_st5);
        if(num2 == 1){
            bin_to_con(persons5, amount_st5);
        }
        if(num2 == 2){
            bin_to_txt(persons5, amount_st5);
        }
    }
    else if(num1 == 6){
        std::ifstream biin6("src_files/surname_grades.bin", std::ios::binary);
        StudentSurnameRecord person6{};
        size_t amount_st6 = amount(biin6, person6);
        StudentSurnameRecord* persons6 = new StudentSurnameRecord[amount_st6];
        read_bin(biin6, persons6, amount_st6);
        if(num2 == 1){
            bin_to_con(persons6, amount_st6);
        }
        if(num2 == 2){
            bin_to_txt(persons6, amount_st6);
        }
    }
    else{
        throw "\nIncorrect option selected!\n";
    }
}