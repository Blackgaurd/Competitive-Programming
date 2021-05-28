// An Animal Contest 2 P2 - Koala Party

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n, a[(int)4e3];
set<int> s;
int main(){
    su(n);
    for (int i=0; i<n; i++){
        su(a[i]);
        s.insert(a[i]);
    }
    if (n == 2){
        if ((a[0] + a[1]) % 2) printf("1\n");
        else printf("2\n");
        return 0;
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if ((a[i] + a[j]) % 2 == 0 && s.count((a[i] + a[j]) / 2)){
                printf("3\n");
                return 0;
            }
        }
    }
    printf("2\n");

    return 0;
}