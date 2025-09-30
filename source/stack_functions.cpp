#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*-----------------------------------------------------------------------------------------------*/

#include "enum.h"
#include "struct.h"
#include "consts_and_defines.h"
#include "stack_functions.h"
#include "error_functions.h"

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackCtor ( Stack_t* stack, size_t capacity ) {

    assert ( stack != nullptr );

    stack->capacity = capacity;
    stack->size = 1;
    stack->data = (STK_ELM_TYPE*) calloc ( capacity + 2, sizeof(STK_ELM_TYPE) );

    for ( size_t ind = 1; ind <= capacity; ind++ ) stack->data[ind] = POISON_NUM;

    stack->data[0] = CANARY_NUM;
    stack->data[capacity + 1] = CANARY_NUM;

    //StackDump(stack);

    ERR_HANDL_PRINT ( stack );

}

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackPush ( Stack_t* stack, STK_ELM_TYPE value ) {

    //printf("sus\n");

    assert ( stack != nullptr );

    ERR_HANDL_PRINT ( stack );

    if ( stack->size >= stack->capacity - 2 ) StackAllocation ( stack );

    stack->data[stack->size++] = value;

    #ifdef DEBUG
    stack->sum_elm_check += value;
    #endif

    //printf("%ld %ld\n", ControlSumCount(stack), stack->sum_elm_check);

    ERR_HANDL_PRINT ( stack );

}

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackPop ( Stack_t* stack, STK_ELM_TYPE* value ) {

    assert ( stack != nullptr );

    ERR_HANDL_PRINT ( stack ) ;

    *value = stack->data[stack->size - 1];

    stack->data[stack->size - 1] = POISON_NUM;
    stack->size--; 

    #ifdef DEBUG
    stack->sum_elm_check -= *value;
    #endif

    ERR_HANDL_PRINT ( stack ) ;

}

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackDtor ( Stack_t* stack ) {

    assert ( stack != nullptr );

    stack->capacity = 0;
    stack->size = 0;
    
    free ( stack->data );
    stack->data = nullptr;

}

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackAllocation ( Stack_t* stack ) {

    stack->data = (STK_ELM_TYPE*) realloc ( stack->data, ( stack->capacity*2 + 2 ) * sizeof(STK_ELM_TYPE) );

    ERR_HANDL_PRINT ( stack );

    for ( size_t ind = stack->size; ind < stack->capacity*2 + 2; ind++ ) stack->data[ind] = POISON_NUM;

    stack->capacity = stack->capacity*2;
    stack->data[stack->capacity + 1] = CANARY_NUM;

}

/*-----------------------------------------------------------------------------------------------*/