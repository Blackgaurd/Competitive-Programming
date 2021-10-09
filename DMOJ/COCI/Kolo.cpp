// COCI '10 Contest 7 #2 Kolo

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 25;
int n, k, s, ptr = 0;
char c, arr[MM];
bool seen[MM];
int main() {
    su(n);
    su(k);
    for (int i = 0; i < n; i++) arr[i] = '?';
    while (k--) {
        su(s);
        sc(c);
        ptr += s;
        ptr %= n;
        if (arr[ptr] == '?') {
            if (seen[c - 'A']) {
                putchar('!');
                return 0;
            }
            seen[c - 'A'] = true;
            arr[ptr] = c;
        } else if (arr[ptr] != c) {
            putchar('!');
            return 0;
        }
    }
    for (int i = ptr, cnt = 0; cnt < n; i--, cnt++) {
        putchar(arr[(i + n) % n]);
    }
    putchar('\n');

    return 0;
}