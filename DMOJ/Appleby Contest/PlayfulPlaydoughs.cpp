// Appleby Contest '20 P2 - Playful Playdoughs

#include <cstdio>
#include <unordered_map>
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
typedef long long ll;

int n, q;
unordered_map<int, ll> mp;
int main() {
    su(n);
    su(q);
    for (int i = 0, a; i < n; i++) {
        su(a);
        mp[a]++;
    }
    for (int a, b; q--;) {
        su(a);
        su(b);
        if (a == 1) {
            int floor = b / 2, ceil = b - floor;
            mp[floor] += mp[b];
            mp[ceil] += mp[b];
            mp[b] = 0;
        } else {
            printf("%lld\n", mp[b]);
        }
    }

    return 0;
}