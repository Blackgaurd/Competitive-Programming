// Mimi and Christmas Cake

#include <cstdio>
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 1e5 + 3;
int n, a, cnt;
bool prime[MM];
void build() {
    prime[1] = true;
    for (int i = 4; i < MM; i += 2) {
        prime[i] = true;
    }
    for (int i = 3; i < MM; i += 2) {
        if (prime[i]) continue;
        for (int j = i + i; j < MM; j += i) {
            prime[j] = true;
        }
    }
}
int main() {
    build();
    su(n);
    while (n--) {
        su(a);
        cnt += !prime[a];
    }
    printf("%d\n", cnt);
}