#ifndef __STACK_FUNC__
#define __STACK_FUNC__

#include "struct.h"
#include "enum.h"


ErrorCode StackCtor       ( Stack_t* stack, size_t capacity );
ErrorCode StackPush       ( Stack_t* stack, int value );
ErrorCode StackPop        ( Stack_t* stack, int* value );
ErrorCode StackDtor       ( Stack_t* stack );
ErrorCode StackAllocation ( Stack_t* stack, StkAllocType alloc_type );


#endif
