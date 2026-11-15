#include "headers/master.h"

int main()
{
    try
    {
        generate_students_info(40);
        // create_bin_info();
        create_bin_grades();
        read_bin();
    }
    catch (const char *err)
    {
        std::cerr << err;
        return -1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return 0;
}