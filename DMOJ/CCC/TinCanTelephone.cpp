// CCC '06 S3 - Tin Can Telephone

#include<stdio.h>
#include<algorithm>
using namespace std;

// one main line,
// up to 3200 building lines
int gcd(int a, int b, int c){
    return __gcd(a, __gcd(b, c));
}
struct line{
    // ax + by + c = 0
    int a, b, c;
    int px, py, qx, qy;
    line(int ppx, int ppy, int qqx, int qqy){
        px = ppx; py = ppy;
        qx = qqx; qy = qqy;

        a = qy - py;
        b = px - qx;
        c = (a * px + b * py) * -1;

        int div = gcd(a, b, c);
        if (div){
            a/=div; b/=div; c/=div;
        }
    }

    bool bound(const line &line_, double interx, double intery){
        return interx >= min(line_.px, line_.qx) && interx <= max(line_.px, line_.qx)
                && intery >= min(line_.py, line_.qy) && intery <= max(line_.py, line_.qy);
    }

    bool intersect(const line &other){
        double interx = (double)(b * other.c - other.b * c) / (double)(a * other.b - other.a * b);
        double intery = (double)(other.a * c - a * other.c) / (double)(a * other.b - other.a * b);

        return bound(*this, interx, intery) && bound(other, interx, intery);
    }
};

int n, ax, ay, bx, by, cx, cy, cnt = 0;
int main(){

    scanf("%d%d%d%d%d", &ax, &ay, &bx, &by, &n);
    line tin = {ax, ay, bx, by};
    for (int e=1; e<=n; e++){
        bool block = false;
        int p; scanf("%d", &p);
        scanf("%d%d", &ax, &ay);
        bx = ax; by = ay;
        for (int i=0; i<p-1; i++){
            scanf("%d%d", &cx, &cy);
            line wall = {bx, by, cx, cy};
            if (!block){
                if (tin.intersect(wall)) block = true;
                bx = cx; by = cy;
            }
        }
        line wall = {ax, ay, bx, by};
        if (tin.intersect(wall)) block = true;
        cnt += block;
    }

    printf("%d\n", cnt);

    return 0;
}
