#ifndef __STRUCTS__
#define __STRUCTS__

#include <stdlib.h>

typedef struct {

    //char* func_name  = nullptr;
    int   line_num   = 0;
    char* file_name  = nullptr;

} Var_Pos_Info; 



typedef struct {

    //Var_Pos_Info pos_info = {};

    int   line_num;
    char* file_name;

    char*  stack_name;
    int*   data;
    size_t size;
    size_t capacity;

} Stack_t;


#endif