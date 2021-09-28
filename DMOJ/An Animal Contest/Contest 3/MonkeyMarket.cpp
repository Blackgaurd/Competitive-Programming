// An Animal Contest 3 P3 - Monkey Market

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 1e6 + 3;
int n;
deque<int> arr;
string out;
int main() {
    su(n);
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        su(arr[i]);
    }
    sort(arr.begin(), arr.end());
    while (true) {
        out += 'B';
        printf("%d", arr.front());
        arr.pop_front();

        if (arr.empty()) break;
        printf(" ");
        out += 'S';
        printf("%d", arr.back());
        arr.pop_back();

        if (arr.empty()) break;
        printf(" ");
    }
    if (n & 1) out.back() = 'E';
    printf("\n%s\n", out.c_str());

    return 0;
}