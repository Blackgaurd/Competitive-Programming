// CCC '16 S5 - Circle of Life

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5;
int n;
ll t;
bool a[MM], b[MM];
int main(){
    scanf("%d%lld\n", &n, &t);
    for (int i=0; i<n; i++){
        a[i] = (getchar() == '1');
    }
    for (ll k=1; k<=t; k<<=1){
        if (t & k){
            for (int i=0; i<n; i++){
                b[i] = a[(i+k%n)%n] ^ a[(i+(n-k%n)%n)%n];
            }
            for (int i=0; i<n; i++){
                a[i] = b[i];
            }
        }
    }
    for (int i=0; i<n; i++){
        printf("%d", a[i]);
    }

    return 0;
}
