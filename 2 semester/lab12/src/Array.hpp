#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

class Array{
    int size;
public:
    int** ReadFile(std::string filename);

    int* SumOfArrays(int** arrays);
    void WriteOut(std::string filename, int* res_arr);    
    void FreeMemory(int** arr, int* res_arr);
    bool isEl(int* position);
};