// USACO 2021 Open Silver P1 - Maze Tac Toe

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

struct node {
    char mark;
    int first, second;
};

int n, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
node arr[26][26];
char board[4][4];
pair<int, int> start;
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c, x, y;
            sc(c);
            sc(x);
            sc(y);
            if (c == 'M' || c == 'O')
                arr[i][j] = {c, x - '0', y - '0'};
            else if (c == '#' || c == '*')
                arr[i][j] = {c, 0, 0};
            else {
                arr[i][j] = {c, 0, 0};
                start = {i, j};
            }
        }
    }
}
