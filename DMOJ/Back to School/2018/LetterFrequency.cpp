// Back To School '18: Letter Frequency

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 1e6 + 3;
char c;
int q, psa[26][MM];
int main() {
    for (int i = 1; (c = getchar()) != '\n'; i++) {
        for (int j = 0; j < 26; j++) psa[j][i] += psa[j][i - 1];
        if (c == ' ') continue;
        psa[c - 'a'][i]++;
    }
    su(q);
    while (q--) {
        int a, b;
        su(a);
        su(b);
        sc(c);
        printf("%d\n", psa[c - 'a'][b] - psa[c - 'a'][a - 1]);
    }

    return 0;
}