// DMOPC '15 Contest 6 P5 - A Classic Problem

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

const int MM = 3e6 + 3;
int n, k, arr[MM];
long long ans = 0;
deque<int> mn, mx;
int main() {
    su(n);
    su(k);
    for (int i = 0; i < n; i++) su(arr[i]);

    for (int l = 0, r = 0; r < n; r++) {
        while (!mx.empty() && mx.back() < arr[r]) mx.pop_back();
        mx.push_back(arr[r]);

        while (!mn.empty() && mn.back() > arr[r]) mn.pop_back();
        mn.push_back(arr[r]);

        while (mx.front() - mn.front() > k) {
            if (mx.front() == arr[l]) mx.pop_front();
            if (mn.front() == arr[l]) mn.pop_front();
            l++;
        }
        ans += r - l + 1;
    }
    printf("%lld\n", ans);

    return 0;
}