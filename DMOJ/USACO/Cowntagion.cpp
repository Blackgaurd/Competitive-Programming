// USACO 2020 December Silver P1 - Cowntagion

#include<bits/stdc++.h>
using namespace std;

int n, in[100005];
int main(){
    scanf("%d", &n);
    for (int i=0; i<n-1; i++){
        int a, b; scanf("%d%d", &a, &b);
        in[a]++; in[b]++;
    }
    in[1]++;
    int day = 0;
    for (int i=1; i<=n; i++){
        if (in[i]==1) continue;
        int cnt = 1;
        while (cnt<in[i]){
            cnt<<=1;
            day++;
        }
    }
    printf("%d\n", day+n-1);

    return 0;

}