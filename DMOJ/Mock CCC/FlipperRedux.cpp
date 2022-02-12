// Mock CCC '20 S2 - Flipper Redux

#include <stdio.h>

#include <utility>
#include <vector>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define sb(x) do{while((_=getchar())<48); x=(_-48);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 2e3 + 3;
int n, row[MM], col[MM];
bool arr[MM][MM];
vector<pair<char, int>> coms;
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sb(arr[i][j]);
            if (arr[i][j]) {
                row[i]++;
                col[j]++;
            }
        }
    }
    if (n == 2 && row[1] + row[2] == 2 && row[1] == row[2] && col[1] == col[2]) {
        // edge case
        printf("2\n");
        if (arr[1][1]) {
            printf("R 1\nC 2\n");
        } else {
            printf("R 1\nC 1\n");
        }
        return 0;
    }
    int fl = n / 2 + 1;
    for (int i = 1; i <= n; i++) {
        if (row[i] >= fl) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j])
                    col[j]--;
                else
                    col[j]++;
                arr[i][j] ^= 1;
            }
            coms.push_back({'R', i});
            row[i] = n - row[i];
        }
    }
    for (int j = 1; j <= n; j++) {
        if (col[j] >= fl) {
            for (int i = 1; i <= n; i++) {
                if (arr[i][j])
                    row[i]--;
                else
                    row[i]++;
                arr[i][j] ^= 1;
            }
            coms.push_back({'C', j});
            col[j] = n - col[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (row[i] >= fl) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j])
                    col[j]--;
                else
                    col[j]++;
                arr[i][j] ^= 1;
            }
            coms.push_back({'R', i});
            row[i] = n - row[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (row[i] || col[i]) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", int(coms.size()));
    for (auto p : coms) {
        printf("%c %d\n", p.first, p.second);
    }

    return 0;
}