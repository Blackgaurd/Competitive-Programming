// USACO 2021 February Bronze P1 - Year of the Cow

#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> years = {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
unordered_map<string, int> names = {{"Bessie", 1200}};
int mod(int a) {
    a %= 12;
    if (a < 0) a += 12;
    return a;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string from, tmp, year, dir, to;
        cin >> from >> tmp >> tmp >> dir >> year >> tmp >> tmp >> to;
        if (dir[0] == 'p') {
            if (names[to] % 12 == years[year])
                names[from] = names[to] - 12;
            else
                names[from] = names[to] - mod(names[to] % 12 - years[year]);
        } else {
            if (names[to] % 12 == years[year])
                names[from] = names[to] + 12;
            else
                names[from] = names[to] + mod(years[year] - names[to] % 12);
        }
    }
    cout << abs(names["Elsie"] - 1200) << '\n';

    return 0;
}