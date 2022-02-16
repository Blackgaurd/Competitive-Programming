// DMOPC '21 Contest 6 P3 - An Art Problem

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

const int MM = 1503;
int n, m, k, arr[MM][MM], step[MM][MM], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
;
deque<pii> q;
int main() {
    su(n);
    su(m);
    su(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            su(arr[i][j]);
            if (arr[i][j]) {
                q.push_back({i, j});
                step[i][j] = 0;
            } else {
                step[i][j] = INT_MAX;
            }
        }
    }
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop_front();
        int val = arr[cx][cy], cstep = step[cx][cy];
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (step[nx][ny] == INT_MAX || (step[nx][ny] == cstep + 1 && arr[nx][ny] > val)) {
                arr[nx][ny] = val;
                step[nx][ny] = cstep + 1;
                if (step[nx][ny] < k) {
                    q.push_back({nx, ny});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}