// 2-dimensional segment tree with point updates

// 1 based indexing

// essentially a segment tree where each node
// in itself is also a segment tree

// outer (main) seg tree will be (x) and inner ones will be (y)
// t[x][y]
// simply for readability

// usage:
// build/update/query _x for the main segment tree

const int MM = 1;
struct range {
    int lx, rx, ly, ry;
} rg[MM * 3][MM * 3];
int n, m, t[MM * 3][MM * 3], arr[MM][MM];
#define func(a, b) a + b
void push_up_y(int indx, int indy) {
    t[indx][indy] = func(t[indx][indy * 2], t[indx][indy * 2 + 1]);
}
void build_y(int lx, int rx, int indx, int ly, int ry, int indy) {
    rg[indx][indy] = {lx, rx, ly, ry};
    if (ly == ry) {
        if (lx == rx) {
            // can also read directly here
            t[indx][indy] = arr[lx][ly];
        } else {
            t[indx][indy] = func(t[indx * 2][indy], t[indx * 2 + 1][indy]);
        }
        return;
    }
    int midy = (ly + ry) / 2;
    build_y(lx, rx, indx, ly, midy, indy * 2);
    build_y(lx, rx, indx, midy + 1, ry, indy * 2 + 1);
    push_up_y(indx, indy);
}
void build_x(int lx, int rx, int indx) {
    if (lx != rx) {
        int midx = (lx + rx) / 2;
        build_x(lx, midx, indx * 2);
        build_x(midx + 1, rx, indx * 2 + 1);
    }
    build_y(lx, rx, indx, 1, m, 1);
}
void update_y(int x, int y, int val, int indx, int indy) {
    auto [lx, rx, ly, ry] = rg[indx][indy];
    if (ly == ry) {
        if (lx == rx)
            t[indx][indy] = val;
        else
            t[indx][indy] = func(t[indx * 2][indy], t[indx * 2 + 1][indy]);
        return;
    }
    int midy = (ly + ry) / 2;
    update_y(x, y, val, indx, indy * 2 + (y > midy));
    push_up_y(indx, indy);
}
void update_x(int x, int y, int val, int indx) {
    if (rg[indx][1].lx != rg[indx][1].rx) {
        int midx = (rg[indx][1].lx + rg[indx][1].rx) / 2;
        update_x(x, y, val, indx * 2 + (x > midx));
    }
    update_y(x, y, val, indx, 1);
}
int query_y(int ly, int ry, int indx, int indy) {
    if (rg[indx][indy].ly == ly && rg[indx][indy].ry == ry) {
        return t[indx][indy];
    }
    int midy = (rg[indx][indy].ly + rg[indx][indy].ry) / 2;
    if (ry <= midy)
        return query_y(ly, ry, indx, indy * 2);
    else if (ly > midy)
        return query_y(ly, ry, indx, indy * 2 + 1);
    return func(query_y(ly, midy, indx, indy * 2), query_y(midy + 1, ry, indx, indy * 2 + 1));
}
int query_x(int lx, int ly, int rx, int ry, int indx) {
    if (rg[indx][1].lx == lx && rg[indx][1].rx == rx) {
        return query_y(ly, ry, indx, 1);
    }
    int midx = (rg[indx][1].lx + rg[indx][1].rx) / 2;
    if (rx <= midx)
        return query_x(lx, ly, rx, ry, indx * 2);
    else if (lx > midx)
        return query_x(lx, ly, rx, ry, indx * 2 + 1);
    return func(query_x(lx, ly, midx, ry, indx * 2), query_x(midx + 1, ly, rx, ry, indx * 2 + 1));
}