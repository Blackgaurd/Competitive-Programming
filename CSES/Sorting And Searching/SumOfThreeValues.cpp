// Sum of Three Values

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

int n, x;
vector<pii> arr;
int main() {
#ifdef PC
    freopen("SumOfThreeValues.in", "r", stdin);
    freopen("SumOfThreeValues.out", "w", stdout);
#endif
    su(n);
    su(x);
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        su(arr[i].first);
        arr[i].second = i + 1;
    }
    if (n < 3) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int needed = x - arr[i].first - arr[j].first;
            if (needed <= 0) continue;
            int lo = j + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (needed < arr[mid].first) {
                    hi = mid - 1;
                } else if (needed > arr[mid].first) {
                    lo = mid + 1;
                } else {
                    printf("%d %d %d\n", arr[i].second, arr[j].second, arr[mid].second);
                    return 0;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
}