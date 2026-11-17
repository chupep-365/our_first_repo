#pragma once

#include "../headers/file_to_bin.h"
#include "../headers/fileRatings.h"
#include "../headers/surname_to_ratings.h"

struct A_s_students{
    char surname[32];
    char group[8];
    char record_book_number[16];
    float av_score;
};

void is_empty(std::streamsize);

void c_a_s_s(std::ifstream&);

void read_bin2();

void calc_average_score_of_students();