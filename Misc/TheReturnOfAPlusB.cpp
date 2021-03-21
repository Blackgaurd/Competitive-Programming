// The Return of A Plus B
// this question is so dumb

#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> numbers = {
    {"1", 1},
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"un", 1},
    {"deux", 2},
    {"trois", 3},
    {"quatre", 4},
    {"cinq", 5},
    {"six", 6},
    {"sept", 7},
    {"huit", 8},
    {"neuf", 9},
    {"dix", 10},
    {"一", 1},
    {"二", 2},
    {"三", 3},
    {"四", 4},
    {"五", 5},
    {"六", 6},
    {"七", 7},
    {"八", 8},
    {"九", 9},
    {"十", 10}
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        string a, b; cin >> a >> b;
        cout << numbers[a]+numbers[b] << '\n';
    }

    return 0;
}