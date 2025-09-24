#ifndef __ERROR_FUNC__
#define __ERROR_FUNC__

#include "struct.h"
#include "enum.h"


void      StackDump ( Stack_t* stack );
ErrorCode StackErrorHandler ( Stack_t* stack );
char*     StackErrorMessage ( ErrorCode status );


#endif