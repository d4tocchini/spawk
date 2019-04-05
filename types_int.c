/* types_int.c */

#include "types_int.h"

int64_t
d_to_i64(double d)
{
    if (d >= INT64_MAX_DOUBLE)
        return INT64_MAX ;
    if (d >  INT64_MIN_DOUBLE)
        return (int64_t) d ;
    return INT64_MIN ;
}

uint64_t
d_to_u64(double d)
{
    if (d >= UINT64_MAX_DOUBLE)
        return UINT64_MAX ;
    if (d >= 0.0)
        return (uint64_t) d ;
    {   // TODO: what?
        int64_t x = INT64_MIN ;
        if (d > INT64_MIN_DOUBLE)
            x = (int64_t) d ;
	    return (uint64_t) x ;
    }
}

int
d_to_int(double d)
{
    if (d >= 2147483647.0)
        return 2147483647 ;
    if (d > -2147483648.0)
        return (int) d ;
    return  -2147483648 ;
}
