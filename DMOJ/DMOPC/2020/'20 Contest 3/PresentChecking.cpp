// DMOPC '20 Contest 3 P1 - Present Checking

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, arr[1000003];
int main(){
    sc(n);
    for (int i=0; i<n; i++){
        int a; sc(a);
        arr[a]++;
    }
    for (int i=0; i<n; i++){
        if (arr[i]>=2){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}