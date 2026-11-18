#pragma once
#include "../headers/create_list_of_st.h"

#include <iostream>
#include <fstream>
#include <cstdlib>   // для std::atoi
#include <algorithm> // для std::sort

struct Smart_array
{
    Key_info_students *arr;
    size_t size;
    size_t top;
    float resize_factor; // на какой коэффициент нужно расширяться
};

void sort_list();
