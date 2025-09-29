#ifndef __STACK_FUNC__
#define __STACK_FUNC__

/*-------------------------------------------------------*/
#include "consts_and_defines.h"
#include "struct.h"
#include "enum.h"
/*-------------------------------------------------------*/

ErrorCode StackCtor       ( Stack_t* stack, size_t capacity );
ErrorCode StackPush       ( Stack_t* stack, STK_ELM_TYPE value );
ErrorCode StackPop        ( Stack_t* stack, STK_ELM_TYPE* value );
ErrorCode StackDtor       ( Stack_t* stack );
ErrorCode StackAllocation ( Stack_t* stack );

/*-------------------------------------------------------*/

#endif
