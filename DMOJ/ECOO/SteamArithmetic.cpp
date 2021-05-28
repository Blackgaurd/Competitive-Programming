// ECOO '12 R3 P3 - Steam Arithmetic

#include<bits/stdc++.h>
using namespace std;

int solve(string t){
    deque<int> q;
    for (int i=t.size()-1; i>=0; i--){
        if (t[i]=='(' || t[i]==')' || t[i]==' ') continue;
        if (t[i]>='0' && t[i]<='9')
            q.push_front(t[i]-'0');
        else {
            int a = q.front();
            q.pop_front();
            int b = q.front();
            q.pop_front();
            if (t[i]=='+')
                q.push_front(a+b);
            else if (t[i]=='-')
                q.push_front(a-b);
            else if (t[i]=='*')
                q.push_front(a*b);
            else if (t[i]=='q')
                q.push_front(a/b);
            else if (t[i]=='r')
                q.push_front(a%b);
        }
    }
    return q.front();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i=0; i<10; i++){
        string t; getline(cin, t);
        cout << solve(t) << '\n';
    }

    return 0;
}