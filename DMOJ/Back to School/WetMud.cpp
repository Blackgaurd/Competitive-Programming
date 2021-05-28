// Back To School '17: Wet Mud

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, m, j, t = 0, dis = 0;
vector<pii> arr;
priority_queue<int, vector<int>, greater<int>> q;
int main(){
    su(n); su(m); su(j);
    for (int i=0; i<m; i++){
        int pi, ti; su(pi); su(ti);
        arr.push_back({ti, pi});
    }
    sort(arr.begin(), arr.end());
    for (pii p: arr){
        t = p.first;
        q.push(p.second);
        while (q.top() - dis <= j && !q.empty()){
            dis = q.top();
            q.pop();
            if (dis == n){
                cout << t << '\n';
                return 0;
            }
        }
    }
    if (n - dis <= j) cout << time << '\n';
    else cout << -1 << '\n';

    return 0;
}