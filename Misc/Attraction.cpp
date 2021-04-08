// Attraction

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; bool _sign;

int t;
int main(){
    su(t);
    while (t--){
        int n, a, b, ans = 0;
        su(n); su(a); su(b);

        vector<int> p;
        for (int i=0; i<a; i++){
            int x; su(x);
            p.push_back(x);
        }
        sort(p.begin(), p.end());

        priority_queue<pii, vector<pii>> q;
        if (p[0] > 1) q.push({p[0] - 1, 0});
        if (p[a-1] < n) q.push({n - p[a-1], 0});
        for (int i=1; i<a; i++){
            if (p[i] != p[i-1] + 1){
                int gap = p[i] - p[i-1] - 1;
                if (gap%2) q.push({(gap + 1) / 2, 3});
                else q.push({gap / 2, 2});
            }
        }
        while (!q.empty() && b > 0){
            pii cur = q.top(); q.pop();
            ans += cur.first;
            b--;
            if (cur.second == 3 && cur.first >= 2) q.push({cur.first - 2, 1});
            if (cur.second == 2) q.push({cur.first, 0});
            if (cur.second == 1) q.push({1, 0});
        }
        printf("%d\n", ans);
    }

    return 0;
}