// An Animal Contest 1 P6 - Alpaca Distancing

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n;
vector<pii> arr, dp;
int main(){
    su(n);
    for (int i=0; i<n; i++){
        int a, b; su(a); su(b);
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    for (pii &p: arr){
        //printf("Current: (%d, %d)\n", p.first, p.second);
        if (dp.empty()) dp.push_back({p.first, p.first + p.second});
        else if ((p.first - p.second >= dp.back().first) && (p.first >= dp.back().second)){
            dp.push_back({p.first, p.first + p.second});
        }
        else if (p.first + p.second < dp.back().second){
            dp.pop_back();
            dp.push_back({p.first, p.first + p.second});
        }
        //printf("dp size: %d\n", dp.size());
    }
    printf("%ld\n", dp.size());

    return 0;
}