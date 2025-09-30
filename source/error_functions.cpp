#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------------------------*/

#include "error_functions.h"
#include "consts_and_defines.h"
#include "struct.h"
#include "enum.h"
#include "colors.h"

/*-----------------------------------------------------------------------------------------------*/

void StackDump ( Stack_t* stack ) {

    #ifdef DEBUG

    //printf("sus\n");

    printf ( "-------------------------\n"
             "stack [%p] %s::line %d\n"
             "-------------------------\n"
             "size = %d\n"
             "capacity = %d\n"
             "data [%p]\n"
             "-------------------------\n",
             stack, stack->file_name, stack->line_num, stack->size, stack->capacity, stack->data );

    #endif

    if ( stack->data != nullptr ) {

        PrintStackElements ( stack );

    }

    #ifdef DEBUG
    printf ( "-------------------------\n" );
    #endif

}

/*-----------------------------------------------------------------------------------------------*/

void PrintStackElements ( Stack_t* stack ) {

    for ( size_t ind = 0; ind < stack->capacity + 2; ind++) {

        if ( ind < stack->size ) {

            printf ( "* [%d] = %s%d%s %s%s%s\n", 
                     ind,
                     BLUE, stack->data[ind], RES_COL,
                     RED, DataSpecialParamHandler ( stack->data[ind] ), RES_COL );

        } else {

            printf ( "  [%d] = %s%d%s %s%s%s\n",
                     ind,
                     BLUE, stack->data[ind], RES_COL,
                     RED, DataSpecialParamHandler ( stack->data[ind] ), RES_COL );

        }
            
    }

}

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackErrorHandler ( Stack_t* stack, bool is_dump ) {

    //printf("sus\n");

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

    // if ( stack->sum_elm_check != ControlSumCount ( stack ) ) {

    //     if ( is_dump ) StackDump ( stack );
    //     return ErrorCode::INCORRECT_CONTROL_SUM_ERROR;

    // }

    return ErrorCode::HANDLED_SUCCSESFULY;

}

/*-----------------------------------------------------------------------------------------------*/

long ControlSumCount ( Stack_t* stack ) {

    long control_elm_sum = 0;

    for ( size_t ind = 1; ind <= stack->size; ind++ ) {

        control_elm_sum += stack->data[ind];
        printf(" %ld %ld\n", control_elm_sum, stack->data[ind]);

    }

    return control_elm_sum;

}

/*-----------------------------------------------------------------------------------------------*/

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