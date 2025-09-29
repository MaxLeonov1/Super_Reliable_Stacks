#ifndef __STRUCTS__
#define __STRUCTS__

/*-------------------------------------------------------*/
#include <stdlib.h>

#include "consts_and_defines.h"
/*-------------------------------------------------------*/

typedef struct {

    #ifdef DEBUG

    int   line_num;
    char* file_name;
    char* stack_name;

    #endif

    STK_ELM_TYPE* data;
    size_t        size;
    size_t        capacity;

} Stack_t;

/*-------------------------------------------------------*/

#endif