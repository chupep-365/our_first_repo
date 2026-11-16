#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

struct StudentRecord
{
    char group[8];
    char record_book_number[16];
    char subject[3][10]; // 3 строки по 10 символов
    int16_t grade[3];
};

void create_bin_grades();
void read_bin();