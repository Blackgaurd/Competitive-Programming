// Back to School '17: New English

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 1e5+3;
int n, m, cnt[26];
struct trp{
    int i, x;
    char c;
    bool operator <(const trp &other){
        return i < other.i;
    }
} arr[MM];
string t;
int main(){
    su(n); su(m);
    for (int i=0; i<m; i++){
        sc(arr[i].c);
        su(arr[i].x);
        su(arr[i].i);
    }
    sort(arr, arr+m);
    for (int i=0; i<m; i++){
        int &cur = cnt[arr[i].c - 'a'];
        cur = max(cur, arr[i].x);
        if (cur > arr[i].i) {
            printf("-1\n");
            return 0;
        }
        for (int j=0; j<arr[i].x; j++) t.push_back(arr[i].c);
    }
    printf("%s\n", t.c_str());

    return 0;
}