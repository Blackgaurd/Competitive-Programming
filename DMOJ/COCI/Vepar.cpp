// COCI '20 Contest 4 #2 Vepar

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

const int MM = 1e7 + 3;
vector<int> prime;
int t;
bool sieve[MM];
bool solve() {
    int a, b, c, d;
    su(a);
    su(b);
    su(c);
    su(d);
}
int main() {
    for (int i = 2; i < MM; i++) {
        if (!sieve[i]) {
            prime.push_back(i);
            for (int j = i + i; j < MM; j += i) sieve[j] = true;
        }
    }
    cout << prime.size() << '\n';
    su(t);
    while (t--) {
        printf("%s\n", solve() ? "DA" : "NE");
    }
}