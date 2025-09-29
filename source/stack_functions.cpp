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

    stack->data = (STK_ELM_TYPE*) calloc ( capacity + 2, sizeof(int) );
    stack->capacity = capacity;
    stack->size = 1;

    for ( size_t ind = 1; ind <= capacity; ind++ ) stack->data[ind] = POISON_NUM;

    stack->data[0] = CANARY_NUM;
    stack->data[capacity + 1] = CANARY_NUM;

    ERR_HANDL_PRINT ( stack );

}

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackPush ( Stack_t* stack, STK_ELM_TYPE value ) {

    assert ( stack != nullptr );

    ERR_HANDL_PRINT ( stack );

    if ( stack->size >= stack->capacity - 2 ) StackAllocation ( stack );

    stack->data[stack->size++] = value;

}

/*-----------------------------------------------------------------------------------------------*/

ErrorCode StackPop ( Stack_t* stack, STK_ELM_TYPE* value ) {

    assert ( stack != nullptr );

    ERR_HANDL_PRINT ( stack ) ;

    *value = stack->data[stack->size - 1];

    stack->data[stack->size - 1] = POISON_NUM;
    stack->size--; 

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

    stack->data = (STK_ELM_TYPE*) realloc ( stack->data, ( stack->capacity*2 + 2 ) * sizeof(long) );

    ERR_HANDL_PRINT ( stack );

    for ( size_t ind = stack->size; ind < stack->capacity*2 + 2; ind++ ) stack->data[ind] = POISON_NUM;

    stack->capacity = stack->capacity*2;
    stack->data[stack->capacity + 1] = CANARY_NUM;

}

/*-----------------------------------------------------------------------------------------------*/