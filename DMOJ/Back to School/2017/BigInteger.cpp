// Back to School '17: Big Integer

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long

int n;
string t, num = "0", sum = "0";
string add(string num1, string num2) {
    if (num1.size() < num2.size()) swap(num1, num2);
    while (num2[0] == '0') num2.erase(0, 1);

    int j = num1.size() - 1;
    for (int i = num2.size() - 1; i >= 0; i--, j--) num1[j] += (num2[i] - '0');

    for (int i = num1.size() - 1; i > 0; i--) {
        if (num1[i] > '9') {
            int d = num1[i] - '0';
            num1[i - 1] = ((num1[i - 1] - '0') + d / 10) + '0';
            num1[i] = (d % 10) + '0';
        }
    }
    if (num1[0] > '9') {
        string k;
        k += num1[0];
        num1[0] = ((num1[0] - '0') % 10) + '0';
        k[0] = ((k[0] - '0') / 10) + '0';
        num1 = k + num1;
    }
    return num1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        if (t[i] == '-')
            num.pop_back();
        else {
            num.push_back(t[i]);
        }
        sum = add(sum, num);
    }
    cout << sum;

    return 0;
}