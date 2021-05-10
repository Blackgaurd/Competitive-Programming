// Mock CCC '21 S2 - Colorful Strings

#include<stdio.h>

#ifndef WIN32
#define getchar getchar_unlocked
#endif

int main(){
    int arr[26];
    long long ans = 1;
    for (int i=0; i<26; i++) arr[i] = 0;
    char c;
    while ((c=getchar()) != '\n'){
        arr[c-'a']++;
    }
    for (int i=0; i<26; i++){
        ans *= arr[i] + 1;
        ans %= (int) 1e9+7;
    }
    printf("%lld\n", ans);

    return 0;
}