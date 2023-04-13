// Increasing Subsequence

#include <stdio.h>

#include <algorithm>
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

int n;
vector<int> lis = {-1};
int main() {
    su(n);
    while (n--) {
        int a;
        su(a);
        if (a > lis.back())
            lis.push_back(a);
        else if (a == lis.back())
            continue;
        else
            *lower_bound(lis.begin(), lis.end(), a) = a;
    }
    printf("%ld\n", lis.size() - 1);

    return 0;
}