// A Coin Problem

#include<bits/stdc++.h>
using namespace std;

struct tripl{
    int first, second, third;
    tripl(int a, int b, int c){
        first = a;
        second = b;
        third = c;
    }
    bool operator < (const tripl& other) const {return first < other.first;}
};
int n, v, dp[10003], maxval = 0;
vector<int> coins;
deque<tripl> q;
deque<pair<int, int>> ans;
int main(){
    scanf("%d%d", &n, &v);
    for (int i=1; i<=n; i++){
        int val; scanf("%d", &val);
        coins.push_back(val);
    }
    for (int i=0; i<v; i++){
        int goal, cnt;
        scanf("%d%d", &goal, &cnt);
        maxval = max(maxval, goal);
        q.push_back({cnt, goal, i});
    }
    
    sort(q.begin(), q.end());
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<n; i++){
        for (int j=coins[i]; j<=maxval; j++){
            dp[j] = min(dp[j], dp[j-coins[i]] + 1);
        }
        if (q.front().first == i+1){
            int sol = (dp[q.front().second] == 0x3f3f3f3f? -1:dp[q.front().second]);
            ans.push_back({q.front().third, sol});
            q.pop_front();
        }
    }

    sort(ans.begin(), ans.end());
    while (!ans.empty()){
        printf("%d\n", ans.front().second);
        ans.pop_front();
    }
    

    return 0;
}