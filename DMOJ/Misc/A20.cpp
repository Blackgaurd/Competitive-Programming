// A20 Gate

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int n;
string s;
string to_upper(string input) {
    for_each(begin(input), end(input), [](char& c) {
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
    });
    return input;
}
int main() {
    for (cin >> n; n--;) {
        cin >> s;
        uint x = stoul(s, nullptr, 16);
        if (x >> 20 & 1) {
            uint low = x & ~(1 << 20);
            stringstream stream;
            stream << setfill('0') << setw(8) << hex << low;
            cout << to_upper(stream.str()) << ' ';
        }
        cout << s << '\n';
    }

    return 0;
}