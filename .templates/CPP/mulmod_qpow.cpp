#include <climits>  // DON'T FORGET THIS

typedef unsigned long long ull;

ull mul_mod(ull __a, ull __b, ull __mod = ULLONG_MAX) {  // __a * __b % __mod
    ull __ret = 0;
    while (__a > 0) {
        if (__a & 1)
            if ((__ret += __b) > __mod) __ret %= __mod;
        __a >>= 1;
        if ((__b <<= 1) > __mod) __b %= __mod;
    }
    return __ret;
}

ull qpow(ull __a, ull __exp, ull __mod = ULLONG_MAX) {  // (__a ^ __exp) % __mod
    if (!__exp) return 1;
    ull __ret = 1;
    while (__exp > 0) {
        if (__exp & 1) __ret = mul_mod(__ret, __a, __mod);
        __a = mul_mod(__a, __a, __mod);
        __exp >>= 1;
    }
    return __ret;
}
