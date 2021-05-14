// DMOPC '19 Contest 6 P2 - Grade 10 Math

#include<bits/stdc++.h>
using namespace std;

int a, b, ans = INT_MAX;
unordered_map<int, int> pf, cnt;
int main(){
    scanf("%d%d", &a, &b);
    while (a % 2 == 0){
        pf[2]++;
        a >>= 1;
    }
    for (int i=3; i<=sqrt(a); i+=2){
        while (a % i == 0){
            pf[i]++;
            a /= i;
        }
    }
    if (a != 1) pf[a] = 1;
    for (int i=2; i<=b; i++){
        int cop = i;
        for (auto &p: pf){
            int add = 0;
            while (cop % p.first == 0){
                add++;
                cop /= p.first;
            }
            cnt[p.first] += add;
        }
    }
    for (auto &p: cnt){
        // printf("%d, %d\n", p.first, p.second);
        ans = min(ans, p.second/pf[p.first]);
    }
    printf("%d\n", ans);

    return 0;
}