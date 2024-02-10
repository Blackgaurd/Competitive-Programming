#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
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

int n;
vector<int> get_moves(int cur) {
    vector<int> ret;
    
}
int solve() {
    unordered_map<int, int> dis;
    int order = 0;

    for (int i = 0, a; i < n; i++) {
        su(a);
        order = order * 10 + a;
    }

    deque<int> q = {order};
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
    }
}

int main() {
    do {
        su(n);
    } while (n);
}