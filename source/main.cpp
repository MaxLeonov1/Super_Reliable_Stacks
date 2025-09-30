#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------*/

#include "consts_and_defines.h"
#include "struct.h"
#include "stack_functions.h"
#include "error_functions.h"
#include "stack_tests.h"

/*-------------------------------------------------------*/

int main() {

    STK_INIT( stk_1 );

    STK_ELM_TYPE value = 0;

    StackCtor ( &stk_1, 5 );

    //printf("%p\n", stk_1.data);
    //StackDump(&stk_1);

    StackPush ( &stk_1, 1 );
    StackPush ( &stk_1, 2 );
    StackPush ( &stk_1, 3 );
    StackPush ( &stk_1, 4 );

    #ifdef DEBUG

    SizeOverflowTest ( &stk_1 );
    CanaryDestructionTest ( &stk_1 );
    //IncorrectControlSumTest ( &stk_1 ); // Защита пока не работает

    #endif

    StackPush ( &stk_1, 5 );

    StackDtor ( &stk_1 );

    return 0;

}