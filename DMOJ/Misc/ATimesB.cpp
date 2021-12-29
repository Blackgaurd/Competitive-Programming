#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <vector>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}
void multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < int(a.size()) + int(b.size()))
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    while (result.back() == 0) {
        result.pop_back();
    }
    for (int i = result.size(); i >= 1; i--) {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }
    for (int i : result) printf("%d", i);
}
int main() {
    #ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> a, b;
    char c;
    while ((c = getchar()) != '\n') {
        a.push_back(c - '0');
    }
    while ((c = getchar()) != '\n') {
        b.push_back(c - '0');
    }
    if (a[0] == 0 || b[0] == 0) {
        printf("0\n");
        return 0;
    }
    // how many trailing zeroes there should be
    int trailing_zeroes = 0;
    for (int i = a.size() - 1; i>=0; i--){
        if (a[i] != 0) break;
        trailing_zeroes++;
    }
    for (int i = b.size() - 1; i>=0; i--){
        if (b[i] != 0) break;
        trailing_zeroes++;
    }
    multiply(a, b);
    while (trailing_zeroes--) putchar('0');
    putchar('\n');
}