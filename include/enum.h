#ifndef __ENUMS__
#define __ENUMS__


/*-------------------------------------------------------*/
typedef enum {

    HANDLED_SUCCSESFULY = 0,  
    ZERO_CAPACITY_ERROR = 1,
    SIZE_OVERFLOW_ERROR = 2,
    STACK_ALLOCATION_ERROR = 3,

} ErrorCode;
/*-------------------------------------------------------*/
typedef enum {

    UP = 0,
    DOWN = 1,

} StkAllocType;
/*-------------------------------------------------------*/


#endif 
