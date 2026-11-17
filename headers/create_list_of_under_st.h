#pragma once

#include "../headers/file_to_bin.h"
#include "../headers/fileRatings.h"
#include "../headers/surname_to_ratings.h"
#include "../headers/calc_average_score_students.h"

struct Key_info_students{
    char surname[32];
    char group[8];
    char record_book_number[16];
};

void c_l_o_u_s(std::ifstream&);

void create_list_of_underperforming_st();

//для отличников

void c_l_o_t_s(std::ifstream&);

void create_list_of_top_st();