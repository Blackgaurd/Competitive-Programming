// CCC '97 S1 - Sentences

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using qi = queue<int>;
using qpii = queue<pii>;
#define ms memset;

int e, n, v, o;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> e;
    for (int i=0; i<e; i++){
        cin >> n >> v >> o;
        string nouns[n], verbs[v], objects[o];
        for (int i=0; i<n; i++) getline(cin, nouns[i]);
        for (int i=0; i<v; i++) getline(cin, verbs[i]);
        for (int i=0; i<o; i++) getline(cin, objects[i]);
        /*for (auto a: nouns){
            cout << a << " ";
            for (auto b: verbs){
                cout << b << " ";
                for (auto c: objects) cout << c << ".\n";
            }
        }*/
    }

    return 0;
}