// Binary Search Tree Test

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

struct node {
    int val, cnt, ht;
    node *l, *r;
    node(int val) : val(val), cnt(0), ht(1){};
};
void insert(node *root, int val) {
    if (root->val == val) {
        root->cnt++;
        return;
    }
    if (val < root->val) {
        if (root->l == nullptr) {
            root->l = new node(val);
        }
        insert(root->l, val);
    } else {
        if (root->r == nullptr) {
            root->r = new node(val);
        }
        insert(root->r, val);
    }
    int lh = root->l == nullptr ? 0 : root->l->ht;
    int rh = root->r == nullptr ? 0 : root->r->ht;
    root->ht = max(lh, rh) + 1;
}
int main() {
    node *root = new node(1);
    for (int i = 2; i <= 10; i++) {
        insert(root, i);
    }
    cout << root->ht;
}
