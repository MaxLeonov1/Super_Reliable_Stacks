#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "stack_functions.h"
#include "error_functions.h"

#define STK_INIT( name ) Stack_t name = { \
.line_num = __LINE__, \
.file_name = __FILE__, \
.stack_name = #name, \
.data = nullptr, \
.size = 0, \
.capacity = 0 }\                       



const int capacity = 5;



int main() {

    // Stack_t stk_1 = { .line_num = __LINE__, 
    //                   .file_name = __FILE__,
    //                   .stack_name = "stk_1",
    //                   .data = nullptr, 
    //                   .size = 0, 
    //                   .capacity = 0 
    //                 };

    STK_INIT( stk_1 );

    int value = 0;

    StackCtor ( &stk_1, capacity );

    StackPush ( &stk_1, 1 );
    StackPush ( &stk_1, 2 );
    StackPush ( &stk_1, 3 );
    StackPush ( &stk_1, 4 );

    StackPop ( &stk_1, &value );

    StackDump ( &stk_1 );

    //printf ( "%d\n", stk_1.data[stk_1.size] );

    StackDtor ( &stk_1 );

    return 0;

}