// An Animal Contest 2 P1 - Koala Konundrum

#include<stdio.h>
char c;
int cnt[26], ans = 0;
int main(){
    while((c=getchar())!='\n');
    while((c=getchar())!='\n') cnt[c-'a']++;
    for (int i=0; i<26; i++) ans += cnt[i]&1;
    printf("%d\n", (ans?ans:1));

    return 0;
}