#include <stdio.h>
#include <stdlib.h>

#include "error_functions.h"
#include "consts_and_defines.h"
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

    if ( stack->data != nullptr ) {

        for ( size_t ind = 0; ind < stack->capacity + 2; ind++) {

            if ( ind < stack->size ) {

                printf ( "* [%d] = %d %s\n", 
                         ind, stack->data[ind], DataSpecialParamHandler ( stack->data[ind] ) );

            } else {

                printf ( "  [%d] = %d %s\n",
                         ind, stack->data[ind], DataSpecialParamHandler ( stack->data[ind] ) );

            }
            
        }

    }

    printf ( "-------------------------\n" );

}

ErrorCode StackErrorHandler ( Stack_t* stack, bool is_dump ) {

    if ( stack->data == nullptr ) {

        if ( is_dump ) StackDump ( stack );
        return ErrorCode::STACK_ALLOCATION_ERROR;

    }

    if ( stack->capacity <= 0 ) {

        if ( is_dump ) StackDump ( stack );
        return ErrorCode::ZERO_CAPACITY_ERROR;

    }

    if ( stack->size <= 0 ) {

        if ( is_dump ) StackDump ( stack );
        return ErrorCode::ZERO_SIZE_ERROR;


    }

    if ( stack->data[0] != CANARY_NUM && stack->data[stack->capacity + 1] != CANARY_NUM ) {

        if ( is_dump ) StackDump ( stack );
        return ErrorCode::SIZE_OVERFLOW_ERROR;
    
    }

    return ErrorCode::HANDLED_SUCCSESFULY;

}

char* DataSpecialParamHandler ( STK_ELM_TYPE param ) {

    switch ( param ) {

        case CANARY_NUM:
            return "(CANARY)";

        case POISON_NUM:
            return "(POISON)";

        default:
            return " ";

    }

}