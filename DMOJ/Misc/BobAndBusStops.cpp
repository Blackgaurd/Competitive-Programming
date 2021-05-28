// Bob and Bus Stops

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

int n, q, a, b;
vector<int> p;
int binupper(int x){
    int lo = 0, hi = n-1, ind = -1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (p[mid] < x) lo = mid + 1;
        else {
            ind = mid;
            hi = mid - 1;
        }
    }
    return ind;
}
int binlower(int x){
    int lo = 0, hi = n-1, ind = -1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (p[mid] > x) hi = mid - 1;
        else {
            ind = mid;
            lo = mid + 1;
        }
    }
    return ind;
}
int main(){
    su(n); su(q);
    for (b=1; b<=n; b++){
        su(a);
        p.push_back(a);
    }
    sort(all(p));

    while (q--){
        su(a); su(b);
        int l = binupper(a), r = binlower(b);
        // printf("l: %d, r: %d\n", l, r);
        if (l == -1 || r == -1) printf("0\n");
        else printf("%d\n", r-l+1);
    }

    return 0;
}