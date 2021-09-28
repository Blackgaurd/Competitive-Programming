// CCC '14 S3 - The Geneva Confection

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

int t;
int main() {
    sc(t);
    while (t--) {
        int n;
        sc(n);
        deque<int> top, side;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            int a;
            sc(a);
            top.push_front(a);
        }
        for (int nxt = 1; nxt <= n;) {
            if (side.front() == nxt) {
                side.pop_front();
                nxt++;
                continue;
            }
            if (top.front() == nxt) {
                top.pop_front();
                nxt++;
                continue;
            } else if (top.size()) {
                side.push_front(top.front());
                top.pop_front();
            } else {
                possible = false;
                break;
            }
        }
        cout << (possible ? 'Y' : 'N') << '\n';
    }
}