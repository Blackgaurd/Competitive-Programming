// Balanced String

#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    int up = 0, lo = 0;
    while ((c = getchar()) != '\n'){
        if (c >= 'a' && c <= 'z') lo++;
        else if (c >= 'A' && c <= 'Z') up++;
    }
    cout << (up == lo ? "YES" : "NO") << '\n';
}