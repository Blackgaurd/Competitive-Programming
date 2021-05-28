// CCO '01 P2 - Coke or Chocolate Milk

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define MP make_pair

// <person> hates <drink>
// <person> wants <drink>
// <person> wants same as <person>
// <person> wants different from <person>
// <person> wants <drink> if <person> gets <drink>

int n;
string ck = "Coke", cm = "chocolate milk";
unordered_map<string, string> mp;
vector<string> split(const string& str, const string& delim=" ") {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int k=0; k<n; k++){
        string t; 
        getline(cin, t);
        cout << t << nl;
        vector<string> cmd = split(t);
        if (cmd[1]=="wants"){
            if (cmd[2]=="chocolate" || cmd[2]==ck){
                if (cmd.size()<=4){
                    mp.insert(MP(cmd[0], cmd[2]==ck?cm:ck));
                }
                else {
                    int ind = 4;
                    if (cmd[2]!=ck) ind++;
                    string p2 = cmd[ind];
                    if (cmd[2]==cmd[ind+2]){
                        mp.insert(MP(cmd[0], "&"+p2));
                    }
                    else {
                        mp.insert(MP(cmd[0], "!"+p2));
                    }
                }
            }
            else if (cmd[2]=="same"){
                mp.insert(MP(cmd[0], "&"+cmd[4]));
            }
            else {
                mp.insert(MP(cmd[0], "!"+cmd[4]));
            }
        }
        else {
            mp.insert(MP(cmd[0], cmd[2]==ck?cm:ck));
        }
    }
    // get input 0
    for (auto i: mp) cout << i.first << ": " << i.second << nl;

    return 0;
}