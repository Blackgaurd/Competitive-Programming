// DMOPC '16 Contest 4 P1 - Fast Exponents

#include<bits/stdc++.h>
using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
int n;
int main(){
    scan(n);
    while (n--){
        long long a; scan(a);
        cout << (__builtin_popcountll(a)==1?'T':'F') << '\n';
    }
    return 0;
}