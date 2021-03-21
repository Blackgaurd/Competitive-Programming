// USACO 2021 February Bronze P1 - Year of the Cow

#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> cows, years = {
    {"Ox", 0},
    {"Tiger", 1},
    {"Rabbit", 2},
    {"Dragon", 3},
    {"Snake", 4},
    {"Horse", 5},
    {"Goat", 6},
    {"Monkey", 7},
    {"Rooster", 8},
    {"Dog", 9},
    {"Pig", 10},
    {"Rat", 11}
};
unordered_map<string, string> names = {{"Bessie", "Ox"}};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cows.insert({"Bessie", 0});
    for (int i=0; i<n; i++){
        string from, tmp, year, dir, to;
        cin >> from >> tmp >> tmp >> dir >> year >> tmp >> tmp >> to;
        names.insert({from, year});
        if (dir == "next"){
            int dis = years[year] + 12 - years[names[to]];
            cows.insert({from, cows[to] + dis});
        }
        else {
            int dis = years[names[to]] + 12 - years[year];
            dis *= -1;
            cows.insert({from, cows[to] + dis});
        }
    }
    cout << abs(cows["Elsie"]) << '\n';
}