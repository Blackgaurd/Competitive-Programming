#include<bits/stdc++.h>
using namespace std;

string t;
int spre = -1, prel = -1, prem = -1, ans = 0;
vector<pair<int, int>> pos;
bool vis[500003];
int findl(int start){
    for (int i=start; i>=0; i--){
        if (t[i] == 'L') return i;
    }
    return -1;
}
int findm(int start){
    for (int i=start; i>=0; i--){
        if (t[i] == 'M') return i;
    }
    return -1;
}
bool findm_(){
    for (int i=0; i<t.size(); i++){
        if (t[i] == 'M') return true;
    }
    return false;
}
void ls(){
    prel = t.size()-1;
    for (int i=0; i<t.size(); i++){
        if (t[i] == 'S'){
            prel = findl(prel);
            if (prel > i){
                swap(t[i], t[prel]);
                ans++;
            }
        }
    }
}
void ms(){
    prem = t.size()-1;
    for (int i=0; i<t.size(); i++){
        if (t[i] == 'S'){
            prem = findm(prem);
            if (prem > i){
                swap(t[i], t[prem]);
                ans++;
            }
        }
    }
}
void lm(){
    prel = t.size()-1;
    for (int i=0; i<t.size(); i++){
        if (t[i] == 'M'){
            prel = findl(prel);
            if (prel > i){
                swap(t[i], t[prel]);
                ans++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    prel = t.size()-1;
    if (!findm_()){
        for (int i=0; i<t.size(); i++){
            if (t[i] == 'S'){
                prel = findl(prel);
                if (prel > i){
                    swap(t[i], t[prel]);
                    ans++;
                }
            }
        }
    }
    else {
        ls();
        ms();
        lm();
    }
    cout << ans << '\n';
    
}