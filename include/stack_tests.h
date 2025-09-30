#ifndef __TESTS__
#define __TESTS__


#include "struct.h"

void SizeOverflowTest        ( Stack_t* stack );
void CanaryDestructionTest   ( Stack_t* stack );
void IncorrectControlSumTest ( Stack_t* stack );


#endif