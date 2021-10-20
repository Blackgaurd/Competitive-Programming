// DMOPC '21 Contest 2 P2 - Scrambling Swaps

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

const int MM = 301;
int n, qq, arr[MM];
deque<pii> q;
int main() {
    su(n);
    su(qq);
    while (qq--) {
        char c;
        sc(c);
        if (c == 'E') {
            int a, b;
            su(a);
            su(b);
            pii ins = {a, b};
            if (!q.empty() && q.front() == ins){
                q.pop_front();
                continue;
            }
            q.push_front(ins);
        } else if (c == 'B') {
            int a, b;
            su(a);
            su(b);
            pii ins = {a, b};
            if (!q.empty() && q.back() == ins){
                q.pop_back();
                continue;
            }
            q.push_back(ins);
        } else {
            for (int i = 1; i <= n; i++) su(arr[i]);
            for (pii p : q) {
                swap(arr[p.first], arr[p.second]);
            }
            for (int i = 1; i <= n; i++) {
                if (i != 1) printf(" ");
                printf("%d", arr[i]);
            }
            printf("\n");
        }
    }
}