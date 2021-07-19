// DMOPC '17 Contest 1 P1 - Fujō Neko

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e3+3;
int r, c, q;
bool arr1[MM], arr2[MM];
int main(){
    su(r); su(c);
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            char a; sc(a);
            if (a == 'X')
                arr1[i] = arr2[j] = true;
        }
    }
    su(q);
    while (q--){
        int a, b; su(a); su(b);
        printf("%c\n", arr1[b-1] || arr2[a-1] ? 'Y' : 'N');
    }

    return 0;
}