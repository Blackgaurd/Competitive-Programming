// Cat Girls

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) while((x=getchar())<=32)
char _; bool _sign;
typedef pair<int, int> pii;

const int MM = 5e5+3;
int n, cur = 0;
ll w, psa[MM], csa[MM];
int main(){
    su(n); su(w);
    for (int i=1; i<=n; i++){
        char c; sc(c);
        if (c == 'A'){
            int p, c; su(p); su(c);
            cur++;
            if (p > w) continue;
            psa[cur] = psa[cur-1] + p;
            csa[cur] = csa[cur-1] + c;

            if (psa[cur] > w){
                
            }
        }
        else cur--;
    }
}