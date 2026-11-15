#include "../headers/calc_average_score_students.h"

void is_empty(std::streamsize size){
    if(size <= 0){
        throw "\nFile is empty!\n";
    }
}

void read_b_file(std::ifstream& bi_fin, char* buffer){
    if(!bi_fin.read(buffer, size)){
        delete[] buffer; 
        throw "\nError reading binary file\n";
    }
}




void calc_average_score_of_students(){
    std::ifstream bi_fin("", std::ios::binary | std::ios::ate);
    is_open(bi_fin);
    std::streamsize size = bi_fin.tellg();
    bi_fin.seekg(0, std::ios::beg);
    is_empty(size);
    char* buffer = new char[size];
    read_b_file(bi_fin, buffer);
    

}


