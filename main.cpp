#include "headers/master.h"

int main()
{
        try
        {
                generate_students_info(40);
                create_bin_info();
                create_bin_grades();
                surname_to_ratings();
                calc_average_score_of_students();
                create_list_of_underperforming_st();
                create_list_of_top_st();
                bin_to_f();
                sort_list();
        }
        catch (const char *err)
        {
                std::cerr << err;
                return -1;
        }
}