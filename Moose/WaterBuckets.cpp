// LCC/Moose '20 Contest 3 S2 - Water Buckets

#include<bits/stdc++.h>
using namespace std;

int n, k, q, lvl[200005], p[200005];
int main(){
    scanf("%d%d%d", &n, &k, &q);
    for (int i=1; i<=q; i++){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        for (int j=a; j<=b; j++){
            lvl[j]+=c;
            if (lvl[j]>=k && !p[j]) p[j] = i;  
        }
    }
    for (int i=1; i<=n; i++){
        printf("%d ", (p[i]?p[i]:-1));
    }

    return 0;
}