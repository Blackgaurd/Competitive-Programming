#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ==================== INITIALIZE ====================
#define __LOCAL_USE (false)
#define __FILE_NAME "data"
#define __INPUT_SIZE (32000 << 10)
#define __OUTPUT_SIZE (32000 << 10)
char __datain[__INPUT_SIZE], __dataout[__OUTPUT_SIZE], __tmpoutput[32];
int __indexin = 0, __indexout = 0, __tmp, __sign;
char __tmpchr;

// ==================== MACRO & FUNCTIONS ====================
#define moveforspaceend()                                            \
    while (__datain[__indexin] == 32 || __datain[__indexin] == 10) { \
        __indexin++;                                                 \
    }
#define su(__x)                                                                          \
    do {                                                                                 \
        moveforspaceend();                                                               \
        for (__x = 0; 47 < (__tmp = __datain[__indexin++]); __x = __x * 10 + __tmp - 48) \
            ;                                                                            \
    } while (false)
#define si(__x)                                                                            \
    do {                                                                                   \
        moveforspaceend();                                                                 \
        __sign = __datain[__indexin++];                                                    \
        if (__sign - 45) {                                                                 \
            __x = __sign;                                                                  \
        } else {                                                                           \
            __x = __datain[__indexin++];                                                   \
        }                                                                                  \
        for (__x -= 48; 47 < (__tmp = __datain[__indexin++]); __x = __x * 10 + __tmp - 48) \
            ;                                                                              \
        if (__sign < 46) {                                                                 \
            __x = -__x;                                                                    \
        }                                                                                  \
    } while (false)
#define ss(__x)                                                                                                                     \
    do {                                                                                                                            \
        moveforspaceend();                                                                                                          \
        __x.clear();                                                                                                                \
        for (__tmpchr = __datain[__indexin++]; __tmpchr != 32 && __tmpchr != 10; __x += __tmpchr, __tmpchr = __datain[__indexin++]) \
            ;                                                                                                                       \
    } while (false)
#define sc(__x)                            \
    do {                                   \
        moveforspaceend();                 \
        __x = (char)__datain[__indexin++]; \
    } while (false)
#define isu(__x)      \
    unsigned int __x; \
    su(__x);
#define isi(__x)      \
    int __x; \
    si(__x);
#define lsu(__x)            \
    unsigned long long __x; \
    su(__x);
#define lsi(__x)   \
    long long __x; \
    si(__x);
#define csc(__x) \
    char __x;    \
    sc(__x);
void ps(string __s) {
    memcpy(__dataout + __indexout, __s.c_str(), __s.size() * sizeof(char));
    __indexout += __s.size();
    __dataout[__indexout++] = '\n';
}
void ps_split(string __s, char __split) {
    memcpy(__dataout + __indexout, __s.c_str(), __s.size() * sizeof(char));
    __indexout += __s.size();
    __dataout[__indexout++] = __split;
}
#define pchrs(__chr, __len)                                    \
    memcpy(__dataout + indexout, __chr, __len * sizeof(char)); \
    __indexout += len;                                         \
    __dataout[__indexout++] = '\n'
#define pchr(__chr)                  \
    __dataout[__indexout++] = __chr; \
    __dataout[__indexout++] = '\n';
#define pchr_split(__chr, __split)   \
    __dataout[__indexout++] = __chr; \
    __dataout[__indexout++] = __split;
void pi(ll __x) {
    __tmp = 0;
    if (__x < 0) {
        __dataout[__indexout++] = '-';
        __x = -__x;
    }
    do {
        __tmpoutput[__tmp++] = __x % 10;
    } while (__x /= 10);
    while (__tmp--) {
        __dataout[__indexout++] = __tmpoutput[__tmp] + '0';
    }
    __dataout[__indexout++] = '\n';
}
void pi_split(ll __x, char __split) {
    __tmp = 0;
    if (__x < 0) {
        __dataout[__indexout++] = '-';
        __x = -__x;
    }
    do {
        __tmpoutput[__tmp++] = __x % 10;
    } while (__x /= 10);
    while (__tmp--) {
        __dataout[__indexout++] = __tmpoutput[__tmp] + '0';
    }
    __dataout[__indexout++] = __split;
}
#define start_program()                   \
    if (__LOCAL_USE) {                    \
        freopen(__FILE_NAME, "r", stdin); \
    }                                     \
    cin.tie(0);                           \
    cout.tie(0);                          \
    ios::sync_with_stdio(0);              \
    fread(__datain, 1, __INPUT_SIZE, stdin);
#define finish_program() fwrite(__dataout, 1, __indexout, stdout);
#define readunsignedint su
#define readint si
#define readchar sc
#define creadunsignedint isu
#define creadint isi
#define creadunsignedlong lsu
#define creadlong lsi
#define creadchar csc
#define printstring ps
#define printchars pchrs
#define printchar pchr
#define printint pi
#define printstring_split ps_split
#define printchar_split pchr_split
#define printint_split pi_split

/* USAGE

There are many functions so I will only
cover a few

int main(){
    int a;
    su(a); // unsigned ints
    si(a); // signed ints
    pi(a); // print ints

    char c;
    sc(c); // chars
    pc(c); // print chars
}

*/