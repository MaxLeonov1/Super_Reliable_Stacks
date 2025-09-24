#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "supporting_functions.h"



void* recalloc ( void* mem_ptr, size_t old_size, size_t new_size ) {

    void* new_mem_ptr = realloc ( mem_ptr, new_size );

    if ( new_size > old_size ) {

        void* mem_res_ptr = (char*)new_mem_ptr + old_size;
        memset ( mem_res_ptr, 0, new_size-old_size );

        printf ("%p\n", mem_res_ptr);

    }

    return new_mem_ptr;

}