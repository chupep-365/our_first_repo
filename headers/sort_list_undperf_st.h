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
void init(Smart_array &s, size_t size);
bool compare_students(const Key_info_students &student1, const Key_info_students &student2);
void resize(Smart_array &s, size_t newsize);
void push(Smart_array &s, const Key_info_students &element);
void sort_list();
void delete_smart_array(Smart_array &s);
