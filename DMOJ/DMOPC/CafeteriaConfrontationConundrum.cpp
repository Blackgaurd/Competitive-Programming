// DMOPC '19 Contest 5 P4 - Cafeteria Confrontation Conundrum

#include<cstdio>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int MM = 1e5+3;
int n, q, arr[MM];
int main(){
    su(n); su(q);
    for (int i=1; i<=n; i++) su(arr[i]);
    for (int i=1; i<=n; i++){
        int a; su(a);
        arr[i] += arr[a];
    }
    while (q--){
        int a, b; su(a); su(b);
        if (a >= b) printf("-1\n");
        else {
            for (int i=1; i<=n; i++){
                if (arr[i] >= b - a){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }

    return 0;
}