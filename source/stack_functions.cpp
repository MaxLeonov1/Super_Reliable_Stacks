#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "enum.h"
#include "struct.h"
#include "stack_functions.h"



ErrorCode StackCtor ( Stack_t* stack, size_t capacity ) {

    assert ( stack != nullptr );

    stack->data = (int*) calloc ( capacity, sizeof(int) );
    stack->capacity = capacity;
    stack->size = 0;

}

ErrorCode StackPush ( Stack_t* stack, int value ) {

    assert ( stack != nullptr );

    stack->data[stack->size++] = value;

}

ErrorCode StackPop ( Stack_t* stack, int* value ) {

    assert ( stack != nullptr );

    *value = stack->data[stack->size - 1];

    stack->data[stack->size - 1] = 0;
    stack->size--; 

}

ErrorCode StackDtor ( Stack_t* stack ) {

    assert ( stack != nullptr );

    stack->capacity = 0;
    stack->size = 0;
    
    free ( stack->data );
    stack->data = nullptr;

}