// CCC '21 S5 - Math Homework

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
typedef long long ll;

const int MM = 150003;
int n, m;
vector<ll> arr;
vector<vector<int>> psa;
struct qry {
    int l, r;
    ll z;
};
vector<qry> queries, tree;
void build(int l, int r, int ind) {
    tree[ind].l = l;
    tree[ind].r = r;
    if (l == r) {
        tree[ind].z = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    tree[ind].z = gcd(tree[ind * 2].z, tree[ind * 2 + 1].z);
}
ll query(int l, int r, int ind) {
    if (tree[ind].l == l && tree[ind].r == r) {
        return tree[ind].z;
    }
    int mid = (tree[ind].l + tree[ind].r) / 2;
    if (r <= mid)
        return query(l, r, ind * 2);
    else if (l > mid)
        return query(l, r, ind * 2 + 1);
    else
        return gcd(query(l, mid, ind * 2), query(mid + 1, r, ind * 2 + 1));
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(m);
    arr.assign(MM, 1);
    psa.assign(17, vector<int>(MM, 0));
    queries.resize(m);
    tree.resize(MM * 3);
    ll maxz = 0;
    for (int i = 0; i < m; i++) {
        su(queries[i].l);
        su(queries[i].r);
        su(queries[i].z);
        maxz = max(maxz, queries[i].z);
        psa[queries[i].z][queries[i].l]++;
        psa[queries[i].z][queries[i].r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        for (int z = 1; z <= maxz; z++) {
            psa[z][i] += psa[z][i - 1];
            if (psa[z][i] != 0) {
                arr[i] = lcm(arr[i], z);
            }
        }
    }
    build(1, n, 1);
    for (auto [a, b, z] : queries) {
        if (query(a, b, 1) != z) {
            printf("Impossible");
            return 0;
        }
    }
    for_each(arr.begin() + 1, arr.begin() + n + 1, [](auto i) { printf("%lld ", i); });
    printf("\n");

    return 0;
}