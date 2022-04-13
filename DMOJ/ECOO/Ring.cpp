// ECOO '20 P4 - Ring

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void mod(ll &a, ll b) {
    a = (b + (a % b)) % b;
}
ll solve() {
    // parse
    const ll MOD = 1e9 + 7;
    int n;
    cin >> n;
    vector<pair<char, ll>> instructions;
    unordered_map<string, int> func_ptr;
    stack<int> prev_jmp;
    string cmd, param;
    int popped = 0;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        char c = cmd[0];

        if (c != 'E') cin >> param;

        int ptr = i - popped;
        switch (c) {
            case 'F':
                instructions.emplace_back('J', 0);
                prev_jmp.push(ptr);
                func_ptr[param] = ptr + 1;
                break;
            case 'E':
                instructions[prev_jmp.top()].second = ptr + 1;
                prev_jmp.pop();
                instructions.emplace_back(c, 0);
                break;
            case 'C':
                instructions.emplace_back(c, func_ptr[param]);
                break;
            case 'S':
                instructions.emplace_back('A', -stoi(param));
                break;
            default:
                instructions.emplace_back(c, stoi(param));
        }

        if (instructions.size() < 2) continue;
        int l = instructions.size();
        if (instructions[l - 1].first == 'A' && instructions[l - 2].first == 'A') {
            instructions[l - 2].second += instructions[l - 1].second;
            mod(instructions[l - 2].second, MOD);
            instructions.pop_back();
            popped++;
        } else if (instructions[l - 1].first == 'M' && instructions[l - 2].first == 'M') {
            instructions[l - 2].second *= instructions[l - 1].second;
            mod(instructions[l - 2].second, MOD);
            instructions.pop_back();
            popped++;
        }
    }

    // execute
    ll x = 0;
    list<int> call_stack;
    call_stack.push_front(0);
    while (call_stack.front() < int(instructions.size())) {
        auto [c, v] = instructions[call_stack.back()];
        switch (c) {
            case 'J':
                call_stack.back() = v;
                break;
            case 'A':
                x += v;
                call_stack.back()++;
                mod(x, MOD);
                break;
            case 'M':
                x *= v;
                call_stack.back()++;
                mod(x, MOD);
                break;
            case 'C':
                call_stack.push_back(v);
                break;
            case 'E':
                call_stack.pop_back();
                call_stack.back()++;
                break;
        }
    }
    return x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
