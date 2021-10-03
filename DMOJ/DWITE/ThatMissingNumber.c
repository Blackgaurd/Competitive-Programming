// DWITE '09 R1 #3 - That Missing Number

#include <stdio.h>
// clang-format off
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
// clang-format on

char cases = 5;
char m, md, ans;
int main() {
    while (cases--) {
        su(m);
        md = (m + 1) % 4;
        ans = md == 0 ? m + 1: md == 1 ? 1 : md == 2 ? m + 2 : 0;
        while (m--) {
            su(md);
            ans ^= md;
        }
        printf("%d\n", ans);
    }

    return 0;
}