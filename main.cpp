#include "headers/master.h"

int main()
{
    try
    {
        generate_students_info(40);
        create_bin_info();
        create_bin_grates();
    }
    catch (const char *err)
    {
        std::cerr << err;
        return -1;
    }
}