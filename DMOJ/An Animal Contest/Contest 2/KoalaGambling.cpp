// An Animal Contest 2 P4 - Koala Gambling

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int t, n, arr[600];
int main(){
    su(t);
    while (t--){
        su(n);
        for (int i=0; i<n; i++) su(arr[i]);
        sort(arr, arr+n);
        if (n&1){
            for (int i=0; i<n-1; i++)
                printf("%d ", arr[i]);
            printf("%d\n", arr[n-1]);
        }
        else if (arr[0] == arr[n-1])
            printf("-1\n");
        else {
            swap(arr[1], arr[n-2]);
            for (int i=0; i<n-1; i++)
                printf("%d ", arr[i]);
            printf("%d\n", arr[n-1]);
        }
    }

    return 0;
}