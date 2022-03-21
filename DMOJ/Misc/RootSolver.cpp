// Root Solver

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const double EPS = 1e-8;
vector<double> a;
void bairstow(int start, double r, double s, int g, vector<double> &roots) {
    if (g < 1) return;
    if (g == 1) {
        roots.push_back(-a[start] / a[start + 1]);
        return;
    }
    if (g == 2) {
        double D = pow(a[start + 1], 2) - 4.0 * a[start] * a[start + 2];
        if (D > 0) {
            roots.push_back((-a[start + 1] + sqrt(D)) / (2.0 * a[start + 2]));
            roots.push_back((-a[start + 1] - sqrt(D)) / (2.0 * a[start + 2]));
        }
        return;
    }
    int n = a.size() - start;
    vector<double> b(n, 0), c(n, 0);
    b[n - 1] = a[start + n - 1];
    b[n - 2] = a[start + n - 2] + r * b[n - 1];
    for (int i = n - 3; i--;) {
        b[i] = a[start + i] + r * b[i + 1] + s * b[i + 2];
    }
    c[n - 1] = b[n - 1];
    c[n - 2] = b[n - 2] + r * c[n - 1];
    for (int i = n - 3; i--;) {
        c[i] = b[i] + r * c[i + 1] + s * c[i + 2];
    }
    double Din = pow(c[2] * c[2] - c[3] * c[1], -1);
    r = r + Din * (c[2] * -b[1] - c[3] * -b[0]);
    s = s + Din * (-c[1] * -b[1] + c[2] * -b[0]);
    if (abs(b[0]) > EPS || abs(b[1]) > EPS) {
        bairstow(start, r, s, g, roots);
        return;
    }
    if (g >= 3) {
        double Dis = (-r * r) - 4.0 * -s;
        if (Dis > 0) {
            roots.push_back((r - sqrt(Dis)) / 2.0);
            roots.push_back((r + sqrt(Dis)) / 2.0);
        }
        bairstow(start + 2, r, s, g - 2, roots);
    }
}
int main() {
    int t;
    cin >> t;
    vector<pair<double, int>> poly;
    while (t--) {
        double c;
        int e;
        cin >> c >> e;
        if (!poly.empty()) {
            while (poly.back().second - 1 != e) {
                poly.push_back({0, poly.back().second - 1});
            }
        }
        poly.push_back({c, e});
    }
    for (auto [c, e] : poly) {
        a.push_back(c);
    }
    for (int i = 0; i < poly[0].second + 1 - poly.size();) {
        a.push_back(0);
    }
    reverse(a.begin(), a.end());
    vector<double> roots;

    bairstow(0, 0.1, 0.1, poly[0].second, roots);
    sort(roots.begin(), roots.end());
    cout << fixed << setprecision(8);
    for (double root: roots) {
        cout << root << ' ';
    }
}