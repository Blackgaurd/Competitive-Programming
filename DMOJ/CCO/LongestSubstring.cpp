// CCO '03 P5 - Longest Substring

#include <stdio.h>

#include <vector>
using namespace std;
// clang-format off
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
typedef unsigned short u16;
typedef unsigned char u8;

vector<u16> arr;
u8 freq[(1 << 16) + 1];
int main() {
    u16 a;
    while (true) {
        su(a);
        if (a == 0) break;
        arr.push_back(a);
    }
    int lp = 0, rp = 0, mx = 0, ans_p = 0;
    while (rp < arr.size()) {
        u16 cur = arr[rp];
        freq[cur]++;
        while (freq[cur] > 1) {
            u16 pre = arr[lp];
            freq[pre]--;
            lp++;
        }
        if (rp - lp + 1 > mx) {
            mx = rp - lp + 1;
            ans_p = rp;
        }
        rp++;
    }
    for (int i = ans_p - mx; i < ans_p; i++) printf("%u\n", arr[i + 1]);
}