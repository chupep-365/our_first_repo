#pragma once

#include "../headers/generator.h"
#include <cstring>

struct Student
{
    char number[16];
    char surname[32]; // по 2 байта на символ + нультерминатор
    char name[32];
    char fname[32];
};

void is_open(std::ifstream &);
void f_to_b_i(std::ifstream &);
void create_bin_info();