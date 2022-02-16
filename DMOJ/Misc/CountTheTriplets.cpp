// Count The Triplets

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

int n, arr[5000], freq[(int)2e6 + 3];
set<pair<int, pii>> ans;
int main() {
    su(n);
    for (int i = 0; i < n; i++) {
        su(arr[i]);
        freq[arr[i]]++;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        freq[i]--;
        for (int j = i + 1; j < n; j++) {
            if (freq[arr[i] + arr[j]]) {
                ans.insert({min(arr[i], arr[j]), {max(arr[i], arr[j]), arr[i] + arr[j]}});
            }
        }
    }
    printf("%d\n", ans.empty() ? -1 : ans.size());

    return 0;
}