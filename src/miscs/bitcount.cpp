#ifndef _MSC_VER
static inline int32_t __attribute__((always_inline))
mm_popcnt_u32(uint32_t x){
    int32_t result;
    __asm__("popcnt %1, %0" : "=r" (result) : "r" (x));
    return result;
}
#else
#	define mm_popcnt_u32 _mm_popcnt_u32
#endif

//-msse4.2 __builtin_popcount GCCの機能なのでICPCでは使えない？
