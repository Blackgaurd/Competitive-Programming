// DMOPC '21 Contest 4 P1 - Tree Shopping

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
// clang-format off
typedef long long ll;

const int MM = 1e3+3;
int n, q;
struct tri {
    int x1, y1, x2, y2;
    double slope;
    bool top;
    tri(int x1, int y1, int x2, int y2, int x3, int y3){
        // x1 y1 always right angle
        this->x1 = x2;
        this->y1 = y2;
        this->x2 = x3;
        this->y2 = y3;
        slope = double(y3 - y2) / double(x3 - x2);
        top = !(x1 < x3 && slope < 0.0 || x1 >= x3 && slope <= 0.0);
    }
    bool contains(int x, int y){
        if (x < min(x1, x2) || x > max(x1, x2) || y < min(y1, y2) || y > max(y1, y2)) return false;
        if (x == x1 && y == y1) return true;
        if (x == x2 && y == y2) return true;
        if (x == x1 && y == y2) return true;
        if (x == x2 && y == y1) return true;
        if (x == x2){
            return false;
        }
        double new_slope = double(y2 - y) / double(x2 - x);
        if (top) return new_slope <= slope;
        else return new_slope >= slope;
    }
};
vector<tri> arr;
int main(){
    #ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    su(n); su(q);
    for (int i=0; i<n; i++){
        int x1, y1, x2, y2, x3, y3;
        si(x1);
        si(y1);
        si(x2);
        si(y2);
        si(x3);
        si(y3);
        arr.push_back({x1, y1, x2, y2, x3, y3});
    }
    while (q--){
        int x, y;
        si(x); si(y);
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (arr[i].contains(x, y)) cnt++;
        }
        printf("%d\n", cnt);
    }
}