// Segment

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
typedef pair<int, int> pii;

int n, ans = 0, pre = 0;
vector<pii> arr;
int main() {
    su(n);
    for (int i = 0, a, b; i < n; i++) {
        su(a);
        su(b);
        arr.emplace_back(b, a);
    }
    sort(arr.begin(), arr.end());
    for (pii &p : arr) {
        if (p.second >= pre) {
            pre = p.first;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}