// CCC '00 S4 - Golf

#include<cstdio>
#include<algorithm>
#include<cstring>

int dis, n, dp[5300];
int main(){
    scanf("%d%d", &dis, &n);

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        int w; scanf("%d", &w);
        for (int j=w; j<=dis; j++){
            dp[j] = std::min(dp[j], dp[j-w]+1);
        }
    }
    if (dp[dis] == 0x3f3f3f3f)
        printf("Roberta acknowledges defeat.\n");
    else printf("Roberta wins in %d strokes.", dp[dis]);

    return 0;
}