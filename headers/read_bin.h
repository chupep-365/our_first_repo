#pragma once

#include "../headers/calc_average_score_students.h"
#include "../headers/create_list_of_st.h"
#include "../headers/file_to_bin.h"
#include "../headers/surname_to_ratings.h"
#include "../headers/fileRatings.h"
#include "../headers/grade_average_score_st.h"

size_t amount(std::ifstream&, A_s_students);//

size_t amount(std::ifstream&, Key_info_students);//

size_t amount(std::ifstream&, Student);//

size_t amount(std::ifstream&, StudentRecord);//

size_t amount(std::ifstream&, StudentSurnameRecord);//

size_t amount(std::ifstream&, Grade_Average);

void read_bin(std::ifstream&, A_s_students*, size_t);//

void read_bin(std::ifstream&, Key_info_students*, size_t);//

void read_bin(std::ifstream&, Student*, size_t);//

void read_bin(std::ifstream&, StudentRecord*, size_t);//

void read_bin(std::ifstream&, StudentSurnameRecord*, size_t);//

void read_bin(std::ifstream&, Grade_Average*, size_t);

void bin_to_txt(A_s_students*, size_t);//

void bin_to_txt(Key_info_students*, size_t);//

void bin_to_txt(Student*, size_t);//

void bin_to_txt(StudentRecord*, size_t);//

void bin_to_txt(StudentSurnameRecord*, size_t);//

void bin_to_txt(Grade_Average*, size_t);

void bin_to_con(A_s_students*, size_t);//

void bin_to_con(Key_info_students*, size_t);//

void bin_to_con(Student*, size_t);//

void bin_to_con(StudentRecord*, size_t);//

void bin_to_con(StudentSurnameRecord*, size_t);//

void bin_to_con(Grade_Average*, size_t);

void bin_to_f();