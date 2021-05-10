// Starry Nights

#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
int r, c;
ll dp[105][3000], ans = -1;
vector<int> arr;
int main(){
    scanf("%d%d", &r, &c);
    for (int i=0; i < (1 << c - 2); i++){
        if ((i & i << 1) == 0 && (i & i << 2) == 0){
            arr.push_back(i);
            dp[0][arr.size()-1] = 1;
            ans++;
        }
    }
    for (int row=1; row<r-1; row++){
        for (int i=0; i<arr.size(); i++){
            int mask = arr[i];
            for (int j=0; j<arr.size(); j++){
                int mask2 = arr[j];
                int check = mask2 | mask2 << 1 | mask2 >> 1;
                if ((check & mask) == 0){
                    dp[row][i] += dp[row-1][j];
                }
            }
            dp[row][i] %= MOD;
            ans = (ans + dp[row][i]) % MOD;
        }
        ans = (ans - dp[row][0] + MOD) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}