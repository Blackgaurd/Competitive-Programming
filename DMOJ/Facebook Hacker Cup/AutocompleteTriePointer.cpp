// Autocomplete
// solved using trie/prefix tree with pointers

#include<bits/stdc++.h>
using namespace std;

int t, n, ans;
string word;
struct node{
    node *arr[26];
};
void insert(node *root){
    bool flag = true;
    node *cur = root;
    for (char c: word){
        c -= 'a';
        if (flag) ans++;
        if (cur->arr[c] == nullptr){
            cur->arr[c] = new node();
            flag = false;
        }
        cur = cur->arr[c];
    }
}
void clear(node *root){
    if (root == nullptr) return;
    for (node *edge: root->arr){
        clear(edge);
    }
    delete root; // deletes contents/memory of root (arr)
    root = nullptr; // deletes the variable itself
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for (int _case=1; _case<=t; _case++){
        cin >> n;
        ans = 0;
        node *root = new node();
        while (n--){
            cin >> word;
            insert(root);
        }
        cout << "Case #" << _case << ": " << ans << '\n';
        clear(root);
    }

    return 0;
}
