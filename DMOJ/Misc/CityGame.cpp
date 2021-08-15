// City Game

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
#define watch(x) cout << (#x) << ": " << x << '\n'

const int MM = 1003;
int t, r, c, h[MM];
char ch;
int hist(){
    h[0] = h[c+1] = -1;
    stack<int> stk;
    stk.push(0);
    int ans = 0;
    for (int i=1; i<=c+1; i++){
        while (h[stk.top()] > h[i]){
            int p = stk.top();
            stk.pop();
            int area = h[p] * (i - stk.top() - 1);
            ans = max(ans, area);
        }
        stk.push(i);
    }
    return ans;
}
int main(){
    su(t);
    while (t--){
        int ans = 0;
        su(r); su(c);
        memset(h, 0, sizeof(h));
        while (r--){
            for (int i=1; i<=c; i++){
                sc(ch);
                if (ch == 'R') h[i] = 0;
                else h[i]++;
            }
            ans = max(ans, hist());
        }
        printf("%d\n", ans * 3);
    }

    return 0;
}