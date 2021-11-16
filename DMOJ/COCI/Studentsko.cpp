// COCI '14 Contest 2 #3 Studentsko
// longest non-decreasing subsequence

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
typedef pair<int, int> pii;

const int MM = 5000;
int n, k;
pii arr[MM];
vector<int> lis = {-1};
int main() {
    su(n);
    su(k);
    for (int i = 0; i < n; i++) {
        su(arr[i].first);
        arr[i].second = i;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        arr[i].first = i / k;
    }
    sort(arr, arr + n,
         [](const pii &a, const pii &b) { return a.second < b.second; });
    for (int i = 0; i < n; i++) {
        int a = arr[i].first;
        if (a >= lis.back())
            lis.push_back(a);
        else
            *upper_bound(lis.begin(), lis.end(), a) = a;
    }
    printf("%ld\n", n - lis.size() + 1);

    return 0;
}