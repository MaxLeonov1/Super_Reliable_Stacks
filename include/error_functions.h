#ifndef __ERROR_FUNC__
#define __ERROR_FUNC__

/*-------------------------------------------------------*/
#include "struct.h"
#include "enum.h"
#include "consts_and_defines.h"
/*-------------------------------------------------------*/

void      StackDump               ( Stack_t* stack );
ErrorCode StackErrorHandler       ( Stack_t* stack, bool is_dump );
char*     DataSpecialParamHandler ( STK_ELM_TYPE param );

/*-------------------------------------------------------*/

#endif