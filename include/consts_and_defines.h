#ifndef __CONSTS__
#define __CONSTS__

/*-------------------------------------------------------*/

#define DEBUG

const int CANARY_NUM = 0xFEE1DEAD;
const int POISON_NUM = 0xDEADFA11;
typedef long STK_ELM_TYPE;

/*-------------------------------------------------------*/       

#ifdef DEBUG 

#define ERR_HANDL_PRINT( stack ) \
    if ( StackErrorHandler( stack, false ) != HANDLED_SUCCSESFULY ) \
    return StackErrorHandler( stack, true )

#else

#define ERR_HANDL_PRINT( stack ) \
    if ( StackErrorHandler( stack, false ) != HANDLED_SUCCSESFULY ) \
    return StackErrorHandler( stack, false )

#endif

/*-------------------------------------------------------*/

#ifdef DEBUG

#define STK_INIT( name ) Stack_t name = { \
.line_num = __LINE__, \
.file_name = __FILE__, \
.stack_name = #name, \
.data = nullptr, \
.size = 0, \
.capacity = 0 }\                       

#else

#define STK_INIT( name ) Stack_t name = { \
.data = nullptr, \
.size = 0, \
.capacity = 0 }\                       


#endif

/*-------------------------------------------------------*/


#endif