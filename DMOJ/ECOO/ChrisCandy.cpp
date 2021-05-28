// ECOO '21 P4 - Chris' Candy

#include<cstdio>
#include<unordered_map>
#include<cmath>
typedef long long ll;

int ttl = 0;
ll k, tempk;
std::unordered_map<ll, int> facs;
int main(){
    scanf("%lld", &k);
    k++;
    tempk = k;
    while (!(k&1)){
        k >>= 1;
        facs[2]++;
        ttl++;
    }
    for (int i=3; i<=sqrt(k); i++){
        while (!(k%i)){
            k /= i;
            facs[i]++;
            ttl += i-1;
        }
    }

    if (k != 1){
        if (k > 100000){
            printf("Sad Chris\n");
            return 0;
        }
        facs[k] = 1;
        ttl += k-1;
    }

    if (ttl > 100000){
        printf("Sad Chris\n");
        return 0;
    }

    printf("%d\n", ttl);
    int ind = 1;
    for (auto p: facs){
        for (int i=0; i<p.second; i++){
            for (int j=1; j<p.first; j++){
                printf("%d ", ind);
            }
            ind++;
        }
    }

    return 0;
}