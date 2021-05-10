// DWITE '09 R6 #2 - Round to power of two

#include<bits/stdc++.h>

int main(){
    for (int i=0, a; i<5; i++){
        std::cin >> a;
        if (a){
            int power = round(log2(a));
            std::cout << (1 << power) << '\n';
        }
        else std::cout << 0 << '\n';
    }

    return 0;
}