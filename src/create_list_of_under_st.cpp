#include "../headers/create_list_of_under_st.h"

void c_l_o_u_s(std::ifstream& fin){
    std::ofstream bi_out("src_files/list_of_underperforming_students.bin", std::ios::binary);
    StudentSurnameRecord student{};
    Key_info_students new_person{};
    while(fin.read(reinterpret_cast<char*>(&student), sizeof(student))){
        if(student.grade[0] < 4 || student.grade[1] < 4 || student.grade[2] < 4){
            strcpy(new_person.surname, student.surname);
            strcpy(new_person.group, student.group);
            strcpy(new_person.record_book_number, student.record_book_number);
            bi_out.write((char*)&new_person, sizeof(new_person));
        }
    }
    bi_out.close();
    fin.close();
    std::cout << "\nDone! List of underperforming students is ready.\n";
}

void create_list_of_underperforming_st(){
    std::ifstream bi_fin("src_files/surname_grades.bin", std::ios::binary);
    is_open(bi_fin);
    c_l_o_u_s(bi_fin);
}