// B. Avoid Local Maximums

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

const int MM = 2e5 + 3;
int t, n, arr[MM];
void solve() {
    su(n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
    }
    arr[n + 1] = arr[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            arr[i + 1] = max(arr[i], arr[i + 2]);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    su(t);
    while (t--) solve();
}