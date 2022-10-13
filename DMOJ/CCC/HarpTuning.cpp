// CCC '22 J3 - Harp Tuning

#include <bits/stdc++.h>

#include <regex>
using namespace std;

string instructions;
int main() {
    cin >> instructions;

    regex pattern("[A-Z]+[+|-][0-9]+");
    auto begin = sregex_iterator(instructions.begin(), instructions.end(), pattern);
    auto end = sregex_iterator();

    while (begin != end) {
        string match = (*begin++).str();
        int split;
        if ((split = match.find('+')) != string::npos) {
            cout << match.substr(0, split) << " tighten " << match.substr(split + 1, match.size()) << '\n';
        } else if ((split = match.find('-')) != string::npos) {
            cout << match.substr(0, split) << " loosen " << match.substr(split + 1, match.size()) << '\n';
        }
    }
}