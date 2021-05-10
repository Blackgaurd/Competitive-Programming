// DMOPC '20 Contest 1 P4 - Victor Makes Bank
// subtask 1

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int mod = 1e9+7;
int N, K, T, C, ans = 0;
int arr[101][101];
void multrep(int a[101][101], int b[101][101]){ // a*=b
    int product[101][101];
    memset(product, 0, sizeof(product));
    for (int i=0; i<=T; i++){
        for (int j=0; j<=T; j++){
            for (int k=0; k<=T; k++){
                product[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    copy(&product[0][0], &product[0][0]+101*101, &a[0][0]);
}
void qpow(int a[101][101], int exp){
    int sol[101][101];
    copy(&a[0][0], &a[0][0]+101*101, &sol[0][0]);
    exp--;
    while (exp) {
        if (exp & 1)
            multrep(sol, arr);
        multrep(arr, arr);
        exp >>= 1;
    }
    copy(&sol[0][0], &sol[0][0]+101*101, &a[0][0]);
}
int main(){
    sc(N); sc(K); sc(T); sc(C);
    arr[0][T] = K;
    arr[T][T] = 1;
    for (int i=1; i<=T; i++) arr[i][i-1] = 1;
    qpow(arr, N-1);
    for (int i=0; i<=T; i++){
        ans+=arr[i][T]*C;
        ans%=mod;
    }
    ans+=arr[T][T]*C;
    ans%=mod;
    cout << ans << '\n';

    return 0;
}