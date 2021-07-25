// Back To School '17: Wet Mud

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
typedef pair<int, int> pii;

const int MM = 1e5+3;
int n, m, j;
pii arr[MM];
bool check(int ind){
    int pos = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i=1; i<=ind; i++){
        // check pq for available next pos
        while (!q.empty() && pos + j >= q.top()){
            pos = max(pos, q.top());
            q.pop();
        }

        // check if next pos can be reached from current pos
        if (pos + j >= arr[i].second){
            pos = max(pos, arr[i].second);
        }

        // else push to pq for later
        else q.push(arr[i].second);
    }
    while (!q.empty() && pos + j >= q.top()){
        pos = max(pos, q.top());
        q.pop();
    }
    return pos + j >= n;
}
int main(){
    su(n); su(m); su(j);
    for (int i=1; i<=m; i++){
        su(arr[i].second);
        su(arr[i].first);
    }
    sort(arr+1, arr+m+1); // sort by time

    // binary search with time
    int lo = 1, hi = m, ans = -1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    if (ans == -1) printf("-1\n");
    else printf("%d\n", arr[ans].first);

    return 0;
}