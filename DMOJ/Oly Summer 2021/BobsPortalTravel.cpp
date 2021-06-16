// Bob's Portal Travel

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
typedef long long ll;

const int MM = 2e5+3;
int n, arr[MM], dis[MM], idx = 0, i, pre;
ll k;
int main(){
    su(n); su(k);
    for (int i=1; i<=n; i++){
        su(arr[i]);
        dis[i] = -1;
    }
    for (i=1; dis[i] == -1; pre = i, i = arr[i], k--){
        if (!k) break;
        dis[i] = idx++;
    }
    k %= (dis[pre] - dis[arr[pre]] + 1);
    for (i=arr[pre]; k; k--, i = arr[i]);
    printf("%d\n", i);

    return 0;
}