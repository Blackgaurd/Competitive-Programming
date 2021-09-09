// Circular Christmas Lights

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e6;
int n, m;
bool a[MM], b[MM];
int main(){
    su(n); su(m);
    for (int i=0; i<n; i++){
        char c; sc(c);
        a[i] = c == '1';
    }
    for (int k=1; k<=m; k<<=1){
        if (m & k){
            for (int i=0; i<n; i++)
                b[i] = a[i] ^ a[(i+k)%n];
            for (int i=0; i<n; i++)
                a[i] = b[i];
        }
    }

    for (int i=0; i<n; i++)
        printf("%d\n", a[i]);

    return 0;
}