// Facebook Hacker Cup 2015 Round 2

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

int t, n;
deque<int> a, b, c;
int main() {
    su(t);
    for (int _case = 1; _case <= t; _case++) {
        a.clear();
        b.clear();
        c.clear();
        su(n);
        for (int i = 0; i < n; i++) {
            int x;
            su(x);
            a.push_back(x);
            c.push_back(x);
        }
        while (!a.empty()) {
            if (b.empty()) {
                b.push_back(a.back());
                a.pop_back();
            } else if (a.front() == b.front() - 1) {
                b.push_front(a.front());
                a.pop_front();
            } else if (a.front() == b.back() + 1) {
                b.push_back(a.front());
                a.pop_front();
            } else if (a.back() == b.front() - 1) {
                b.push_front(a.back());
                a.pop_back();
            } else if (a.back() == b.back() + 1) {
                b.push_back(a.back());
                a.pop_back();
            } else
                break;
        }
        if (a.empty()) {
            printf("Case #%d: yes\n", _case);
            continue;
        }

        b.clear();
        while (!c.empty()) {
            if (b.empty()) {
                b.push_back(c.front());
                c.pop_front();
            } else if (c.front() == b.front() - 1) {
                b.push_front(c.front());
                c.pop_front();
            } else if (c.front() == b.back() + 1) {
                b.push_back(c.front());
                c.pop_front();
            } else if (c.back() == b.front() - 1) {
                b.push_front(c.back());
                c.pop_back();
            } else if (c.back() == b.back() + 1) {
                b.push_back(c.back());
                c.pop_back();
            } else
                break;
        }
        printf("Case #%d: %s\n", _case, (c.empty() ? "yes" : "no"));
    }

    return 0;
}
