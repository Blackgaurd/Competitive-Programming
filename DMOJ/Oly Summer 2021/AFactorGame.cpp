// A Factor Game

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n, arr[(int)1e5+3], ans[(int)1e6+3], cnt[(int)1e6+3];
int main(){
    su(n);
    for (int i=1; i<=n; i++){
        su(arr[i]);
        cnt[arr[i]]++;
    }
    for (int i=1; i<=n; i++){
        int cur = arr[i];
        if (!ans[cur]){
            for (int i=1; i<=sqrt(cur); i++){
                if (cur % i == 0){
                    ans[cur] += cnt[i];
                    if (i*i != cur){
                        ans[cur] += cnt[cur / i];
                    }
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
        printf("%d\n", ans[arr[i]] - 1);
    }

    return 0;
}