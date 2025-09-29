#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------*/

#include "consts_and_defines.h"
#include "struct.h"
#include "stack_functions.h"
#include "error_functions.h"

/*-------------------------------------------------------*/

int main() {

    STK_INIT( stk_1 );

    STK_ELM_TYPE value = 0;

    StackCtor ( &stk_1, 5 );

    StackPush ( &stk_1, 1 );
    StackPush ( &stk_1, 2 );
    StackPush ( &stk_1, 3 );
    StackPush ( &stk_1, 4 );

    StackPop ( &stk_1, &value );
    StackPop ( &stk_1, &value );
    StackPop ( &stk_1, &value );
    StackPop ( &stk_1, &value );
    StackPop ( &stk_1, &value );

    // StackDump ( &stk_1 );

    StackDtor ( &stk_1 );

    return 0;

}