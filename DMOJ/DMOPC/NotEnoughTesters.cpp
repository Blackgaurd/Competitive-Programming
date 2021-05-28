// DMOPC '14 Contest 3 P4 - Not Enough Testers!

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
#define all(arr) arr.begin(),arr.end()

const int MM = 1e5+3;
int t, k, a, b, facs;
vector<int> arr[130];
int main(){
    for (int i=2; i<=(int)1e5; i++){
        facs = 2;
        double sq = sqrt(i);
        for (int j=2; j<=sq; j++){
            if (i % j == 0) facs += 2;
        }
        if ((int)sq == sq) facs--;
        arr[facs].push_back(i);
    }
    su(t);
    while (t--){
        su(k); su(a); su(b);
        if (k == 1){
            if (a == 1) printf("1\n");
            else printf("0\n");
            continue;
        }
        if (k > 128){
            printf("0\n");
            continue;
        }
        int l = lower_bound(arr[k].begin(), arr[k].end(), a) - arr[k].begin();
        int r = upper_bound(arr[k].begin(), arr[k].end(), b) - arr[k].begin();
        printf("%d\n", r-l);
    }

    return 0;
}