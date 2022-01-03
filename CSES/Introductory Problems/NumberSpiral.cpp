// Number Spiral

#include<cstdio>
typedef long long ll;

int t, x, y;
ll solve(int x, int y) {
    ll arm = x > y ? x : y;
    ll pos = (x - y) * (arm & 1 ? 1 : -1) + arm - 1;
    return arm * arm - pos;
}
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &x, &y);
        printf("%lld\n", solve(x, y));
    }
}