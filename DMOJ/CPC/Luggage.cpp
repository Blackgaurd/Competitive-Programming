// CPC '19 Contest 1 P2 - Luggage

#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n, k, ans = 1;
vector<int> h;
int main(){
    su(n); su(k);
    for (int i=0; i<n; i++){
        int a; su(a);
        h.push_back(a);
    }
    h.push_back(INT_MAX);
    sort(h.begin(), h.end());
    for (int i=0; i<n; i++){
        int tallest = h[i] + k;
        int ind = lower_bound(h.begin(), h.end(), tallest) - h.begin();
        //if (ind == n) continue;
        if (h[ind] > tallest) ind--;
        //printf("%d: %d, %d: %d\n", i, h[i], ind, h[ind]);
        ans = max(ans, ind-i+1);
    }
    printf("%d\n", ans);

    return 0;
}