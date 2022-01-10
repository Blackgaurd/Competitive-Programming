// CCC '96 S2 - Divisibility by 11

#include <bits/stdc++.h>
using namespace std;

string diff(string num1, string num2) {
    string sol = "";
    int n1 = num1.size(), n2 = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub = ((num1[i] - '0') - (num2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        sol += (sub + '0');
    }

    for (int i = n2; i < n1; i++) {
        int sub = ((num1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        sol += (sub + '0');
    }
    reverse(sol.begin(), sol.end());
    while (sol[0] == '0') sol = sol.substr(1, sol.size() - 1);
    return sol;
}
int n;
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        string cop = t;
        while (t.size() > 2) {
            cout << t << '\n';
            string last = string(1, t.back());
            t.pop_back();
            t = diff(t, last);
        }
        cout << t << '\n';
        cout << "The number " << cop << " is" << (stoi(t) % 11 == 0 ? "" : " not") << " divisible by 11.\n";
        if (i < n - 1) cout << '\n';
    }

    return 0;
}