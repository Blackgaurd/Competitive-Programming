// Roger's Homework

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

int n;
long long ans;
vector<pii> arr;
struct cmp {
    bool operator()(const pii &a, const pii &b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};
priority_queue<pii, vector<pii>, cmp> q;
int main() {
    su(n);
    arr.resize(n);
    for (auto &[a, b] : arr) {
        su(a);
        su(b);
    }
    sort(arr.begin(), arr.end());
    for (int i = arr.back().first; i >= 1; i--) {
        while (i == arr.back().first) {
            q.push(arr.back());
            arr.pop_back();
        }
        if (!q.empty()) {
            ans += q.top().second;
            q.pop();
        }
    }
    printf("%lld\n", ans);
}