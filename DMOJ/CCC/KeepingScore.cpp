// CCC '01 S1 - Keeping Score

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

string t;
int total = 0;
int solve(string suit) {
    if (suit.size() <= 3) return 4 - suit.size();
    int points = 0;
    for (int i = 0; i < suit.size(); i++) {
        if (suit[i] <= '9') continue;
        switch (suit[i]) {
            case 'J':
                points += 1;
                break;
            case 'Q':
                points += 2;
                break;
            case 'K':
                points += 3;
                break;
            case 'A':
                points += 4;
                break;
        }
    }
    return points;
}
void print(string suit, string begin) {
    cout << begin << " ";
    for (int i = 1; i < suit.size(); i++) {
        cout << suit[i] << " ";
    }
    int p = solve(suit);
    total += p;
    cout << p << nl;
}
int main() {
    cin >> t;
    int C = t.find('C'), D = t.find('D'), H = t.find('H'), S = t.find('S');
    string clubs = t.substr(C, D - C), diamonds = t.substr(D, H - D),
           hearts = t.substr(H, S - H), spades = t.substr(S, t.size() - S);
    cout << "Cards Dealt Points\n";
    print(clubs, "Clubs");
    print(diamonds, "Diamonds");
    print(hearts, "Hearts");
    print(spades, "Spades");
    cout << "Total " << total << nl;

    return 0;
}