#pragma once
#include "../headers/sort_list_students.h"

struct Grade_Average
{
    char surname[32];
    char record_book_number[16];
    float av_score;
};

bool sort_student_alph(const Grade_Average &student1, const Grade_Average &student2);
bool sort_students_av_score(const Grade_Average &student1, const Grade_Average &student2);
void grade_av_score(int16_t specified_group);
void get_group_info();