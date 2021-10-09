// CCC '13 S2 - Bridge Transport

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

int w, n;
deque<int> q;
int main() {
    su(w);
    su(n);
    int sum = 0;
    for (int i = 1, a; i <= n; i++) {
        su(a);
        if (q.size() == 4) {
            sum -= q.back();
            q.pop_back();
        }
        sum += a;
        if (sum > w) {
            printf("%d\n", i - 1);
            return 0;
        }
        q.push_front(a);
    }
    printf("%d\n", n);

    return 0;
}