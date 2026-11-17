#pragma once

#include <iostream>
#include <fstream>

struct StudentSurnameRecord
{
    char surname[32];
    char group[8];
    char record_book_number[16];
    char subject[3][10];
    int16_t grade[3];
};
void surname_to_ratings();