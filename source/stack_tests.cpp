#include <stdlib.h>
#include <stdio.h>

/*-------------------------------------------------------*/

#include "enum.h"
#include "colors.h"
#include "struct.h"
#include "consts_and_defines.h"
#include "stack_tests.h"
#include "stack_functions.h"

/*-------------------------------------------------------*/

void SizeOverflowTest ( Stack_t* stack ) {

    printf ( "%sInicialise SizeOverflowTest\n%s", GREEN, RES_COL );

    stack->size += stack->capacity;
    //printf("sus\n");

}

/*-------------------------------------------------------*/

void CanaryDestructionTest ( Stack_t* stack ) {

    printf ( "%sInicialise CanaryDestructioTest\n%s", GREEN, RES_COL );

    stack->data[0] = 0xDEADCA11;
    stack->data[stack->capacity + 1] = 0xDEADCA11;

    //printf("sus\n");

}

/*-------------------------------------------------------*/

void IncorrectControlSumTest ( Stack_t* stack ) {

    printf ( "%sInicialise CanaryDestructioTest\n%s", GREEN, RES_COL );

    stack->data[1] = 0xAB0BA;

}