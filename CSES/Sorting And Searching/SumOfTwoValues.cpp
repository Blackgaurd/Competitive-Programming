// Sum of Two Values

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

int n, k;
vector<pii> arr;
int main(){
    su(n); su(k);
    arr.resize(n);
    for (int i=0; i<n; i++){
        su(arr[i].first);
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    int lo = 0, hi = n - 1;
    while (lo < hi){
        int sum = arr[lo].first + arr[hi].first;
        if (sum < k) lo++;
        else if (sum > k) hi--;
        else {
            printf("%d %d\n", arr[lo].second, arr[hi].second);
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");

    return 0;
}
