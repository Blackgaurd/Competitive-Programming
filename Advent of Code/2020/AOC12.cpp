// 

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

// 791 lines
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    /*
    part 1
    ll x = 0, y = 0, dir = 0;
    int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
    while (true){
        string t; cin >> t;
        if (t=="0") break;
        char c = t[0]; int n = stoi(t.substr(1, t.size()-1));
        if (c=='F'){
            while (n--){
                x+=dx[dir]; y+=dy[dir];
            }
        }
        else if (c=='N') y+=n;
        else if (c=='S') y-=n;
        else if (c=='E') x+=n;
        else if (c=='W') x-=n;
        else if (c=='R') dir = (dir+n/90)%4;
        else if (c=='L') dir = (dir+4-n/90)%4;
    }
    cout << x << " " << y << nl;
    cout << abs(x)+abs(y) << nl;
    */
    int x = 0, y = 0, waypoint[2] = {1, 10};
    int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
    while (true){
        string t; cin >> t;
        if (t=="0") break;
        
        char c = t[0]; int n = stoi(t.substr(1, t.size()-1));
        if (c=='F'){
            x+=n*waypoint[0];
            y+=n*waypoint[1];
        }
        else if (c=='N') waypoint[0]+=n;
        else if (c=='S') waypoint[0]-=n;
        else if (c=='E') waypoint[1]+=n;
        else if (c=='W') waypoint[1]-=n;
        else if (c=='R'){
            if (n==180) {waypoint[0]*=-1; waypoint[1]*=-1;}
            else if (n==90){
                int tmp = waypoint[1];
                waypoint[1]=waypoint[0];
                waypoint[0] = tmp*-1;
            }
            else{
                int tmp = waypoint[0];
                waypoint[0]=waypoint[1];
                waypoint[1] = tmp*-1;
            }
        }
        else if (c=='L'){
            if (n==180) {waypoint[0]*=-1; waypoint[1]*=-1;}
            else if (n==90){
                int tmp = waypoint[0];
                waypoint[0]=waypoint[1];
                waypoint[1] = tmp*-1;
            }
            else{
                int tmp = waypoint[1];
                waypoint[1]=waypoint[0];
                waypoint[0] = tmp*-1;
            }
        }
        //cout << t << ": " << "x: " << waypoint[0] << ", y: " << waypoint[1] << nl;
    }
    cout << x << " " << y << nl;
    cout << abs(x)+abs(y) << nl;

    return 0;
}