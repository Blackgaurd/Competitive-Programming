// CCC '14 S3 - The Geneva Confection

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int t;
int main(){
    sc(t);
    while (t--){
        int n; sc(n);
        deque<int> top, side;
        bool possible = true;
        for (int i=0; i<n; i++){
            int a; sc(a);
            top.push_front(a);
        }
        for (int nxt = 1; nxt<=n;){
            if (side.front()==nxt){side.pop_front(); nxt++; continue;}
            if (top.front()==nxt){top.pop_front(); nxt++; continue;}
            else if (top.size()){
                side.push_front(top.front());
                top.pop_front();
            }
            else {possible = false; break;}
        }
        cout << (possible?'Y':'N') << '\n';
    }
}