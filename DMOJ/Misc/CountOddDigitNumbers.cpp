// Count Odd Digit Numbers
// Sorry for cheesing
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n, total = 0;
    cin >> n;
    int len = floor(log10(n))+1;
    if (len%2==0){
        if (len==2) cout << 9;
        else if (len==4) cout << 909;
        else if (len==6) cout << 90909;
        else if (len==8) cout << 9090909;
        else if (len==10) cout << 909090909;
        else if (len==12) cout << 90909090909;
        else if (len==14) cout << 9090909090909;
        else if (len==16) cout << 909090909090909;
        else if (len==18) cout << 90909090909090909;
    } else{
        if (len==1) cout << n;
        else if (len==3) cout << 9+n-100+1;
        else if (len==5) cout << 909+n-10000+1;
        else if (len==7) cout << 90909+n-1000000+1;
        else if (len==9) cout << 9090909+n-100000000+1;
        else if (len==11) cout << 909090909+n-10000000000+1;
        else if (len==13) cout << 90909090909+n-1000000000000+1;
        else if (len==15) cout << 9090909090909+n-100000000000000+1;
        else if (len==17) cout << 909090909090909+n-10000000000000000+1;
        else if (len==19) cout << 90909090909090909+n-1000000000000000000+1;
    }

    return 0;
}