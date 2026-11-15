#include "headers/master.h"

int main()
{
    generate_students_info(40);
    std::cout << '\n';
    create_bin_grates();
    std::cout << "Binary file was created" << '\n';
    read_bin();
    return 0;
}