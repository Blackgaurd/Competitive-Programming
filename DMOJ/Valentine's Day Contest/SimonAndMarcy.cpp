// Simon and Marcy
// Valentine's Day 2015 Contest

#include<bits/stdc++.h>
using namespace std;
#define iosync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using pii = pair<int, int>;
#define val first
#define weight second

int c, m, mem[1003][1003];
vector<pii> items;
int knapsack(int i, int w){
    if (i==0 || w==0){
        mem[i][w] = 0;
        return 0;
    }
    else if (mem[i][w]!=0){
        return mem[i][w];
    }
    else if (items[i].weight>w){
        mem[i][w] = knapsack(i-1, w);
        return mem[i][w];
    }
    else {
        mem[i][w] = max(items[i].val + knapsack(i-1, w - items[i].weight), knapsack(i-1, w));
        return mem[i][w];
    }
}
int main(){
    iosync;
    cin >> c >> m;
    for (int i=0; i<c; i++){
        int n, k; cin >> n >> k;
        items.push_back({n, k});
    }
    int ans = knapsack(c, m);
    cout << ans << '\n';
    
    return 0;
}