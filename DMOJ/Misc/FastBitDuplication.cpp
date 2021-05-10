// Fast Bit Duplication
#include<bits/stdc++.h>
using namespace std;
unsigned long long duplicatebits(unsigned long long n){
    unsigned long long tmp = n|(n<<1)|(n<<2);
    n = tmp-n; 

    return n;
}
uint32_t interleave(uint8_t value)
{
    uint32_t x = value;
    x = (x | (x << 4)) /* & 0x000F000F */; // GCC is not able to remove redundant & here
    x = (x | (x <<  3)) & 0x03030303;
    x = (x | (x << 2)) & 0x11111111;
    x = (x << 2) - x;
    return x;
}

int main(){
    unsigned long long a = 3;
    cout << interleave(a);
}