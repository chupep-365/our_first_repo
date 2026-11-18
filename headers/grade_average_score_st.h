#pragma once

struct Grade_Average
{
    char surname[32];
    char record_book_number[16];
    float av_score;
};

struct Smart_Average_array
{
    Grade_Average *arr;
    size_t size;
    size_t top;
    float resize_factor;
};

bool sort_student_alph(const Grade_Average &student1, const Grade_Average &student2);
bool sort_students_av_score(const Grade_Average &student1, const Grade_Average &student2);
void grade_av_score(const char *);