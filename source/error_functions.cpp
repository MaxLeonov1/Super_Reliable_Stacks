#include <stdio.h>
#include <stdlib.h>

#include "error_functions.h"
#include "struct.h"
#include "enum.h"



void StackDump ( Stack_t* stack ) {

    printf ( "-------------------------\n"
             "stack [%p] %s::line %d\n"
             "-------------------------\n"
             "size = %d\n"
             "capacity = %d\n"
             "data [%p]\n"
             "-------------------------\n",
             stack, stack->file_name, stack->line_num, stack->size, stack->capacity, stack->data );

    for ( size_t ind = 0; ind < stack->capacity; ind++) {

        if ( ind < stack->size ) {

            printf ( "* [%d] = %d\n", ind, stack->data[ind] );

        } else {

            printf ( "  [%d] = %d\n", ind, stack->data[ind] );

        }
        
    }

    printf ( "-------------------------\n" );

}

ErrorCode StackErrorHandler ( Stack_t* stack ) {

    if ( stack->capacity == 0 )
        return ErrorCode::ZERO_CAPACITY_ERROR;

    if ( stack->size >= stack->capacity )
        return ErrorCode::SIZE_OVERFLOW_ERROR;

    if ( stack->data == nullptr )
        return ErrorCode::STACK_ALLOCATION_ERROR;

    return ErrorCode::HANDLED_SUCCSESFULY;

}

char* StackErrorMessage ( ErrorCode status ) {

    if ( status == ErrorCode::ZERO_CAPACITY_ERROR )
        return "Stack has zero capacity";

    if ( status == ErrorCode::SIZE_OVERFLOW_ERROR )
        return "Size is more than capacity";

}