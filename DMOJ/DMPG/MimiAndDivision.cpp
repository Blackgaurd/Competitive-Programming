// DMPG '18 S5 - Mimi and Division
// doesnt work without fast io

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 2e5 + 3;
int n, q, len;
struct factors {
    vector<int> arr;
    factors() {
        arr.assign(MM, 0);
    }
    void insert(int num) {
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                arr[i]++;
                if (i * i != num) arr[num / i]++;
            }
        }
    }
    void remove(int num) {
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                arr[i]--;
                if (i * i != num) arr[num / i]--;
            }
        }
    }
};
int main() {
    su(n);
    su(q);
    len = sqrt(n) + 1;
    vector<int> arr(n);
    vector<factors> blocks(len, factors());
    for (int i = 0; i < n; i++) {
        su(arr[i]);
        blocks[i / len].insert(arr[i]);
    }
    while (q--) {
        int com;
        su(com);
        if (com == 1) {
            int l, r, x;
            su(l);
            su(r);
            su(x);
            l--;
            r--;
            int cnt = 0;
            for (int i = l; i <= r;) {
                if (i % len == 0 && i + len - 1 <= r) {
                    cnt += blocks[i / len].arr[x];
                    i += len;
                } else {
                    cnt += arr[i] % x == 0;
                    i++;
                }
            }
            printf("%d\n", cnt);
        } else {
            int u, v;
            su(u);
            su(v);
            u--;
            blocks[u / len].remove(arr[u]);
            blocks[u / len].insert(v);
            arr[u] = v;
        }
    }
}