#pragma once
#include "../headers/create_list_of_st.h"

#include <iostream>
#include <fstream>
#include <cstdlib>   // для std::atoi
#include <algorithm> // для std::sort

template <class T>
struct Smart_array
{
    T *arr;
    size_t size;
    size_t top;
    float resize_factor; // на какой коэффициент нужно расширяться
};
template <class T>
void init(Smart_array<T> &s, size_t size);
bool compare_students(const Key_info_students &student1, const Key_info_students &student2);
template <class T>
void resize(Smart_array<T> &s, size_t newsize);
template <class T>
void push(Smart_array<T> &s, const T &element);
void sorting(const char *inputpath, const char *outputpath, const char *specified_group);
void sorted_group_list();
template <class T>
void delete_smart_array(Smart_array<T> &s);
