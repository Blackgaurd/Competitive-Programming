// Robot Path Decoding

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
typedef pair<long long, long long> pii;

const int MOD = 1e9;
int t;
void mod(long long &a) {
    a %= MOD;
    if (a < 0) a += MOD;
}
pii solve(string s) {
    // cout << "parsing: " << s << '\n';
    pii ret = {0, 0};
    int flag = 0, bracket = 0;
    string pass = "";
    for (int i = 0; i < s.size(); i++) {
        if (flag != 0) {
            pass.push_back(s[i]);
            if (s[i] == '(')
                bracket++;
            else if (s[i] == ')') {
                bracket--;
                if (bracket == 0) {
                    pii mini = solve(pass.substr(1, pass.size() - 2));
                    ret.first += mini.first * flag;
                    ret.second += mini.second * flag;
                    mod(ret.first);
                    mod(ret.second);
                    flag = 0;
                    pass.clear();
                }
            }
            continue;
        }
        if (s[i] == 'N') {
            ret.second--;
        } else if (s[i] == 'S') {
            ret.second++;
        } else if (s[i] == 'W') {
            ret.first--;
        } else if (s[i] == 'E') {
            ret.first++;
        } else if ('2' <= s[i] && s[i] <= '9') {
            flag = s[i] - '0';
        }
        // cout << ret.first << ' ' << ret.second << '\n';
    }
    mod(ret.first);
    mod(ret.second);
    return ret;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i=1; i<=t; i++){
        string s;
        cin >> s;
        pii ans = solve(s);
        cout << "Case #" << i << ": " << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }
}
