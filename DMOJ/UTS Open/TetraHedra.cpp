// UTS Open '15 #6 - Tetrahedra

// for each of the 8 total triangles:
// - find area using cross product
// - find plane using normal and one point
// - for each vector in other tetrahedral:
//   - if two endpoints are on opposite sides of plane
//   - intersect line with plane, add to set
//   - convert all points to 2d
// - shoelace theorem to find intersecting area of two triangles
// - subtract this area from area of triangle

// answer is sum of these operations repeated 8 times

#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pii;

struct Point {
    double x, y, z;
    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Point operator-(const Point &other) {
        return Point(x - other.x, y - other.y, z - other.z);
    }
    Point cross(const Point &other) {
        // cross product
        return Point(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x);
    }
    double dot(const Point &other) {
        return x * other.x + y * other.y + z * other.z;
    }
    Point operator/(double val) {
        return Point(x / val, y / val, z / val);
    }
    double abs() {
        // magnitude
        return sqrt(x * x + y * y + z * z);
    }
};
typedef Point Vec3;

const int SZ = 4;
vector<Point> t1, t2;
double sign(pii &A, pii &B, pii &C) {
    return (A.first - C.first) * (B.second - C.second) - (B.first - C.first) * (A.second - C.second);
}
bool in_triangle(pii &point, pii &A, pii &B, pii &C) {
    double d1 = sign(point, A, B), d2 = sign(point, B, C), d3 = sign(point, C, A);
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}
bool in_poly(pii &point, vector<pii> &poly) {  // poly has 4 sides
    if (in_triangle(point, poly[0], poly[1], poly[2])) return true;
    if (in_triangle(point, poly[0], poly[1], poly[3])) return true;
    if (in_triangle(point, poly[0], poly[2], poly[3])) return true;
    return false;
}
pii center;
bool poly_cmp(pii &a, pii &b) {
    if (a.first - center.first >= 0 && b.first - center.first < 0)
        return true;
    if (a.first - center.first < 0 && b.first - center.first >= 0)
        return false;
    if (a.first - center.first == 0 && b.first - center.first == 0) {
        if (a.second - center.second >= 0 || b.second - center.second >= 0)
            return a.second > b.second;
        return b.second > a.second;
    }

    // compute the cross product of vectors (center -> a) x (center -> b)
    double det = (a.first - center.first) * (b.second - center.second) - (b.first - center.first) * (a.second - center.second);
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    // points a and b are on the same line from the center
    // check which point is closer to the center
    double d1 = (a.first - center.first) * (a.first - center.first) + (a.second - center.second) * (a.second - center.second);
    double d2 = (b.first - center.first) * (b.first - center.first) + (b.second - center.second) * (b.second - center.second);
    return d1 > d2;
}
double ix, iy;
bool intersect_line(pii a, pii b, pii c, pii d) {
    auto [p0x, p0y] = a;
    auto [p1x, p1y] = b;
    auto [p2x, p2y] = c;
    auto [p3x, p3y] = d;

    double s1x = p1x - p0x;
    double s1y = p1y - p0y;
    double s2x = p3x - p2x;
    double s2y = p3y - p2y;

    double s = (-s1y * (p0x - p2x) + s1x * (p0y - p2y)) / (-s2x * s1y + s1x * s2y);
    double t = (s2x * (p0y - p2y) - s2y * (p0x - p2x)) / (-s2x * s1y + s1x * s2y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
        ix = p0x + (t * s1x);
        iy = p0y + (t * s1y);
        return true;
    }

    return false;
}
double shoelace(vector<pii> points) {
    double left = 0, right = 0;

    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        left += points[i].first * points[j].second;
        right += points[j].first * points[i].second;
    }

    return 0.5 * abs(left - right);
}
double get_area(Point &A, Point &B, Point &C, vector<Point> &other) {
    Vec3 AB = B - A, AC = C - A, BC = C - B;
    Vec3 cross = AB.cross(AC);

    // area of triangle
    double full_area = abs(0.5 * cross.abs());

    // normal vector
    Vec3 normal = cross / cross.abs();

    // intersection of vector with plane:
    // if two points are on different side of plane:
    // position = (o1, o2, o3)  X
    // direction = (d1, d2, d3) XY
    // plane (point) = (a1, a2, a3) A
    // plane (normal) = (A-B)*(B-C) = (N1, N2, N3)
    // (x, y, z) = (o1 + d1*t, o2 + d2*t, o3 + d3*t)
    // plane equation: N1(x - a1) + N2(y - a2) + N3(z - a3) = 0
    // solve for t: N1(o1 + d1*t - a1) + N2(o2 + d2*t - a2) + N3(o3 + d3*t - a3) = 0
    // t = (N1(a1 - o1) + N2(a2 - o2) + N3(a3 - o3)) / (N1*d1 + N2*d2 + N3*d3)
    // plug t back into (x, y, z)

    vector<Point> inter;  // intersections
    vector<Point> pos, neg;
    for (int i = 0; i < SZ; i++) {
        Vec3 AX = other[i] - A;
        if (AX.dot(normal) > 0.0)
            pos.push_back(other[i]);
        else
            neg.push_back(other[i]);
    }
    auto [N1, N2, N3] = AB.cross(BC);
    auto [a1, a2, a3] = A;
    for (auto X : pos) {
        auto [o1, o2, o3] = X;
        for (auto Y : neg) {
            auto [d1, d2, d3] = Y - X;
            double t = N1 * (a1 - o1) + N2 * (a2 - o2) + N3 * (a3 - o3);
            t /= N1 * d1 + N2 * d2 + N3 * d3;
            inter.emplace_back(o1 + d1 * t, o2 + d2 * t, o3 + d3 * t);
        }
    }

    // translate points to 2d
    Vec3 x = AB / AB.abs();
    Vec3 y = x.cross(normal);
    pii A2d = {0, 0};  // check this
    pii B2d = {(B - A).dot(x), (B - A).dot(y)};
    pii C2d = {(C - A).dot(x), (C - A).dot(y)};
    vector<pii> inter_2d;
    for (auto &p3d : inter) {
        inter_2d.emplace_back((p3d - A).dot(x), (p3d - A).dot(y));
    }
    // sort inter_2d
    if (!inter_2d.empty()) {
        center = {0, 0};
        for (auto [x, y] : inter_2d) {
            center.first += x;
            center.second += y;
        }
        center.first /= (double)inter_2d.size();
        center.second /= (double)inter_2d.size();
        sort(inter_2d.begin(), inter_2d.end(), poly_cmp);
    }

    // find overlapping area between ABC and points in inter_2d;
    vector<pii> overlap;

    // case 1: point part of inter_2d and inside ABC
    for (auto p : inter_2d) {
        if (in_triangle(p, A2d, B2d, C2d)) {
            overlap.push_back(p);
        }
    }

    // case 2: point part of ABC and inside inter_2d
    if (inter_2d.size() == 3) {
        if (in_triangle(A2d, inter_2d[0], inter_2d[1], inter_2d[2]))
            overlap.push_back(A2d);
        if (in_triangle(B2d, inter_2d[0], inter_2d[1], inter_2d[2]))
            overlap.push_back(B2d);
        if (in_triangle(C2d, inter_2d[0], inter_2d[1], inter_2d[2]))
            overlap.push_back(C2d);
    } else if (inter_2d.size() == 4) {
        if (in_poly(A2d, inter_2d))
            overlap.push_back(A2d);
        if (in_poly(B2d, inter_2d))
            overlap.push_back(B2d);
        if (in_poly(C2d, inter_2d))
            overlap.push_back(C2d);
    }

    // case 3: intersection of borders between ABC and inter_2d
    for (int i = 0; i < (int)inter_2d.size() - 1; i++) {
        if (intersect_line(A2d, B2d, inter_2d[i], inter_2d[i + 1]))
            overlap.emplace_back(ix, iy);
        if (intersect_line(B2d, C2d, inter_2d[i], inter_2d[i + 1]))
            overlap.emplace_back(ix, iy);
        if (intersect_line(A2d, C2d, inter_2d[i], inter_2d[i + 1]))
            overlap.emplace_back(ix, iy);
    }
    if (!inter_2d.empty()) {
        if (intersect_line(A2d, B2d, inter_2d.front(), inter_2d.back()))
            overlap.emplace_back(ix, iy);
        if (intersect_line(B2d, C2d, inter_2d.front(), inter_2d.back()))
            overlap.emplace_back(ix, iy);
        if (intersect_line(A2d, C2d, inter_2d.front(), inter_2d.back()))
            overlap.emplace_back(ix, iy);
    }

    // sort overlap vertices
    if (!overlap.empty()) {
        center = {0, 0};
        for (auto [x, y] : overlap) {
            center.first += x;
            center.second += y;
        }
        center.first /= (double)overlap.size();
        center.second /= (double)overlap.size();
        sort(overlap.begin(), overlap.end(), poly_cmp);
        return full_area - shoelace(overlap);
    }
    return full_area;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < SZ; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        t1.emplace_back(x, y, z);
    }
    for (int i = 0; i < SZ; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        t2.emplace_back(x, y, z);
    }
    double total = 0.0;
    for (int i = 0; i < SZ; i++) {
        for (int j = i + 1; j < SZ; j++) {
            for (int k = j + 1; k < SZ; k++) {
                total += get_area(t1[i], t1[j], t1[k], t2);
                total += get_area(t2[i], t2[j], t2[k], t1);
            }
        }
    }
    cout << fixed << setprecision(8) << total << '\n';
}
