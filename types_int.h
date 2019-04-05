#ifndef MAWK_INT_H
#define MAWK_INT_H

#include <limits.h>
#include <stdint.h>
#include <math.h>

#define             MAX__INT            0x7fffffff
#define             MAX_INT_DOUBLE      9007199254740991.0          // 2^53-1
#define             MIN_INT_DOUBLE      -9007199254740991.0         // 2^53-1
#define             INT64_MAX_DOUBLE    9223372036854775807.000000  // 2^63-1
#define             INT64_MIN_DOUBLE    -9223372036854775808.000000 // -2^63
#define             UINT64_MAX_DOUBLE   18446744073709551615.000000 // 2^64-1
/*

extern const int    have_long64;    // removed

- https://stackoverflow.com/questions/26166010/gcc-arm-c-compiler-not-respecting-std-c99-for-llx-printf-formatting-code
- https://stackoverflow.com/questions/12468281/should-i-use-long-long-or-int64-t-for-portable-code

If long long is present, it must have at least 64 bits, so casting from (u)int64_t to (unsigned) long long is value-preserving.

If you need a type with exactly 64 bits, use (u)int64_t, if you need at least 64 bits, (unsigned) long long is perfectly fine, as would be (u)int_least64_t

*/
#if     LONG_MAX == 0x7fffffffffffffffL
#   define          LONG64              1
#   define          LDFMT               "%ld"
#elif   LONG_MAX == 0x7fffffffL
#   define          LONG32              1
#   define          LDFMT               "%lld"
#else
#   error "unexpected value for LONG_MAX"
#endif
#if     LONG64
#   define          HAS_LONG64          1
#   define          LONG64_LEN_DEC      2
#else
#   define          HAS_LONG64          0
#   define          LONG64_LEN_DEC      3
#endif
                    // can be represented EXACTLY as an int w/ 8 byte double
#define             is_int_double( x )  (      ( x ) == floor( x )      \
                                            && ( x ) <= MAX_INT_DOUBLE  \
                                            && ( x ) >= MIN_INT_DOUBLE  \
                                        )
uint64_t            d_to_u64( double );
int64_t             d_to_i64( double );
int                 d_to_int( double );

// extern const double MAX_INT_DOUBLE; /* 2^53-1 */
// extern const double MIN_INT_DOUBLE; /* -2^53+1 */
// extern const double INT64_MAX_DOUBLE;
// extern const double INT64_MIN_DOUBLE;
// extern const double UINT64_MAX_DOUBLE;

#endif
