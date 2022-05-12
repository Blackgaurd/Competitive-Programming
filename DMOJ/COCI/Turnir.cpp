// COCI '16 Contest 6 #3 Turnir

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

int n;
vector<int> arr, ans;
int qlog2(int x) {
    return 31 - __builtin_clz(x);
}
int main() {
    su(n);
    arr.resize(1 << n);
    ans.resize((1 << n) + 1);
    for (int &a : arr) su(a);
    vector<int> cpy = arr;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        ans[arr[i]] = qlog2(i + 1);
    }

    for (int a: cpy) {
        printf("%d ", n - ans[a]);
    }
}