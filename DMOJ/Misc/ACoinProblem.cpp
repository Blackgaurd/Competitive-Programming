// A Coin Problem

#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
#include<string.h>
using namespace std;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; bool _sign;

struct trp{
    int first, second, third;
    bool operator < (trp const& other){
        return first < other.first;
    }
};
int n, v, val[2003], dp[10003];
deque<trp> stores;
vector<pair<int, int>> ans;
int main(){
    su(n); su(v);
    for (int i=1; i<=n; i++) su(val[i]);
    for (int i=0; i<v; i++){
        int a, b; su(a); su(b);
        stores.push_back({b, a, i});
    }
    sort(stores.begin(), stores.end());

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        for (int j=val[i]; j<=10003; j++){
            dp[j] = min(dp[j], dp[j-val[i]]+1);
        }
        while (i == stores.front().first){
            ans.push_back({stores.front().third, (dp[stores.front().second] == 0x3f3f3f3f? -1:dp[stores.front().second])});
            stores.pop_front();
            if (stores.empty()) break;
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i: ans) printf("%d\n", i.second);

    return 0;
}
