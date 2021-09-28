// DMOPC '19 Contest 6 P1 - Grade 9 Math

#include <algorithm>
#include <iomanip>
#include <iostream>

struct line {
    // ax + by + c = 0
    int a, b, c;
    int px, py, qx, qy;
    line(int ppx, int ppy, int qqx, int qqy) {
        px = ppx;
        py = ppy;
        qx = qqx;
        qy = qqy;

        a = qy - py;
        b = px - qx;
        c = (a * px + b * py) * -1;

        int gcd = std::__gcd(a, std::__gcd(b, c));
        if (gcd) {
            a /= gcd;
            b /= gcd;
            c /= gcd;
        }
    }
};

int x1, y1, x2, y2;
int main() {
    std::cin >> x1 >> y1 >> x2 >> y2;
    line a = {x1, y1, x2, y2};
    std::cin >> x1 >> y1 >> x2 >> y2;
    line b = {x1, y1, x2, y2};

    if (a.a == b.a && a.b == b.b) {
        if (a.c == b.c)
            std::cout << "concident\n";
        else
            std::cout << "parallel\n";
    } else {
        double x =
            double(a.b * b.c - b.b * a.c) / double(a.a * b.b - b.a * a.b);
        double y =
            double(b.a * a.c - a.a * b.c) / double(a.a * b.b - b.a * a.b);
        std::cout << std::fixed;
        std::cout << std::setprecision(6);
        std::cout << x << ' ' << y << '\n';  // printing "inf" whyyyy
    }

    return 0;
}