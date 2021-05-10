// An Easy Problem
// is this similar to longest increasing subsequence?

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, a, dp[(int)1e5], arr[(int)1e5], ans = 0;;
vector<int> lis;
bool comp(int a, int b){ return a & b; }
void nlogn(){
    while (n--){
        su(a);
        if (lis.empty() || a&lis.back()) lis.push_back(a);
        else {
            *upper_bound(lis.begin(), lis.end(), a, comp) = a;
        }
    }
    printf("%d\n", lis.size());
}
void n2(){
    for (int i=0; i<n; i++){
        su(arr[i]);
        dp[i] = 1;
    }
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[i] & arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}
int main(){
    su(n);
    if (n <= 100) n2();
    else nlogn();

    return 0;
}