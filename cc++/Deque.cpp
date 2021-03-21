// Deque

#include<bits/stdc++.h>
using namespace std;

int n, x = 0, y = 0;
bool turn = true; // true = x, false = y
deque<int> q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0, a; i<n; i++){
        cin >> a;
        q.push_back(a);
    }
    while (!q.empty()){
        if (q.front()>=q.back)
    }

    return 0;
}
