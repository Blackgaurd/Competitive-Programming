// CCC '22 J2 - Fergusonball Ratings

#include <bits/stdc++.h>
using namespace std;

int n, star_players = 0;
int main() {
    cin >> n;
    for (int i = n; i--;) {
        int points, fouls, rating;
        cin >> points >> fouls;

        rating = 5 * points - 3 * fouls;
        star_players += rating > 40;
    }

    cout << star_players << (star_players == n ? "+" : "") << "\n";
}