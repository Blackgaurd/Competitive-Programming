// Segment

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int n;
vector<pii> arr;
mii mp;
int main(){
    su(n);
    for (int i=0; i<n; ++i){
        int a, b; su(a); su(b);
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    for (pii &p: arr){
        mii::iterator it = mp.lower_bound(p.first);
        if (it == mp.begin()){
            cout << p.second << " begin\n";
            mp.insert({p.second, 1});
        }
        else {
            mp.insert({p.second, mp[it -> first] + 1});
        }
    }
    cout << '\n';
    for (auto it = mp.begin(); it!=mp.end(); it++){
        cout << it -> first << ' ' << it -> second << '\n';
    }

    return 0;
}

// dp[i] = dp[i+1] + 1
// dp[i+1] is next value where start > cur_end