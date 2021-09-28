// TSS Club Fair 2017 Problem B

#include <math.h>

#include <algorithm>
#include <cstdio>
#include <vector>
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

int n, q, x, y, r;
vector<int> houses;
int main() {
    su(n);
    su(q);
    while (n--) {
        si(x);
        si(y);
        houses.push_back(ceil(hypot(x, y)));
    }
    sort(houses.begin(), houses.end());
    while (q--) {
        su(r);
        int ind = upper_bound(houses.begin(), houses.end(), r) - houses.begin();
        printf("%d\n", ind);
    }

    return 0;
}