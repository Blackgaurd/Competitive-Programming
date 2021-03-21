#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return (a/gcd(a, b)) * b;
}

signed main(){
    //int dep; cin >> dep;
    //vector<int> times;
    //string t; cin >> t;
    /*for (int i=0; i<t.size(); i++){
        if (t[i]=='x'){
            times.push_back(0);
            continue;
        }
        int cur = 0;
        while (isdigit(t[i])){
            cur = cur*10+t[i]-'0';
            i++;
        }
        if (cur){
            i--;
            
            part 1
            cout << cur << " x " << cur*(dep/cur+1)-dep << " = " << cur*(cur*(dep/cur+1)-dep) << nl;
            
            times.push_back(cur);
        }
    }
    */
    int increment = 17, start = 0;
    cout << lcm(17, 41) << nl;;
    cout << "done" << nl;
    for (int i=start;;i+=increment){
        if ((i+7)%41==0){
            increment = lcm(increment, 41);
            start = i;
            break;
        }
    }
    for (int i=start;;i+=increment){
        if ((i+17)%983==0){
            increment = lcm(increment, 983);
            start = i;
            break;
        }
    }
    for (int i=start;;i+=increment){
        if ((i+19)%29==0){
            increment = lcm(increment,29);
            start = i;
            break;
        }
    }
    for (int i=start;;i+=increment){
        if ((i+36)%19==0){
            increment = lcm(increment,19);
            start = i;
            break;
        }
    }
    for (int i=start;;i+=increment){
        if ((i+40)%23==0){
            increment = lcm(increment,23);
            start = i;
            break;
        }
    }
    for (int i=start;;i+=increment){
        if ((i+48)%397==0){
            increment = lcm(increment,397);
            start = i;
            break;
        }
    }
    for (int i=start;;i+=increment){
        if ((i+54)%37==0){
            increment = lcm(increment,37);
            start = i;
            break;
        }
    }
    for (int i=start;;i+=increment){
        if ((i+61)%13==0){
            increment = lcm(increment,13);
            start = i;
            break;
        }
    }
    cout << start << nl;
    return 0;
}