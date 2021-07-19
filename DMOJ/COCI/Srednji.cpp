// COCI '07 Contest 1 #5 Srednji

#include<cstdio>
#include<unordered_map>
#include<utility>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
#define before first
#define after second

int n, b, ans = 0, ind = 0;
unordered_map<int, pair<int, int>> mp;
int main(){
    su(n); su(b);
    for (int i=1, a, prev=0; i<=n; i++){
        su(a);
        if (a > b) prev++;
        else if (a < b) prev--;
        else ind = prev;

        if (a != b){
            if (ind) mp[prev].after++;
            else mp[prev].before++;
        }
    }
    mp[0].before++;
    for (auto p: mp)
        ans += (p.second.before * p.second.after);
    ans += mp[ind].before;

    printf("%d\n", ans);

    return 0;
}