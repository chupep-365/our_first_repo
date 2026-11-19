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
void init(Smart_array<T> &s, size_t size)
{
    s.size = size;
    s.arr = new T[size];
    s.top = 0;
    s.resize_factor = 1.67;
}

template <class T>
void resize(Smart_array<T> &s, size_t newsize)
{
    if (s.size == newsize)
    {
        return;
    }
    T *newarr = new T[newsize];
    for (int16_t i = 0; i < s.size; ++i)
    {
        newarr[i] = s.arr[i];
    }
    delete[] s.arr;
    s.arr = newarr;
    s.size = newsize;
}

template <class T>
void push(Smart_array<T> &s, const T &element)
{
    if (s.size == s.top)
    {
        size_t newsize = (size_t)(s.size * s.resize_factor);
        resize(s, newsize);
    }
    s.arr[s.top++] = element;
}

template <class T>
void delete_smart_array(Smart_array<T> &s)
{
    delete[] s.arr;
    s.arr = nullptr;
    s.size = 0;
    s.top = 0;
}

template <class T>
void init(Smart_array<T> &s, size_t size);
bool compare_students(const Key_info_students &student1, const Key_info_students &student2);
template <class T>
void resize(Smart_array<T> &s, size_t newsize);
template <class T>
void push(Smart_array<T> &s, const T &element);
void sorting(const char *inputpath, const char *outputpath);
void sorted_list();
template <class T>
void delete_smart_array(Smart_array<T> &s);
