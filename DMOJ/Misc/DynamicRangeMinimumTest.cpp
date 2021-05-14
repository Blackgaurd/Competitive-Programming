// Dynamic Range Minimum Test

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e5;
int n, m, a, b, arr[MM], seg[MM * 4];
char c;
void build(int cur, int tl, int tr){
    if (tl == tr) seg[cur] = arr[tl];
    else {
        int tm = (tl + tr) / 2;
        build(cur*2, tl, tm);
        build(cur*2+1, tm+1, tr);
        seg[cur] = min(seg[cur*2], seg[cur*2+1]);
    }
}
void update(int cur, int tl, int tr, int pos, int val){ // update arr[pos] = val
    if (tl == tr) seg[cur] = val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(cur*2, tl, tm, pos, val);
        else
            update(cur*2+1, tm+1, tr, pos, val);
        seg[cur] = min(seg[cur*2], seg[cur*2+1]);
    }
}
int query(int cur, int tl, int tr, int l, int r){ // minimum in arr[l..r]
    if (l > r) return INT_MAX;
    if (l == tl && r == tr) return seg[cur];
    int tm = (tl + tr) / 2;
    int left = query(cur*2, tl, tm, l, min(tm, r));
    int right = query(cur*2+1, tm+1, tr, max(l, tm+1), r);
    return min(left, right);
}
int main(){
    su(n); su(m);
    for (int i=0; i<n; i++) su(arr[i]);
    build(1, 0, n-1);
    while (m--){
        sc(c); su(a); su(b);
        if (c == 'M')
            update(1, 0, n-1, a, b);
        else
            printf("%d\n", query(1, 0, n-1, a, b));
    }

    return 0;
}