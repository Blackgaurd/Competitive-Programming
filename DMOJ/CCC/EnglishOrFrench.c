// CCC '11 S1 - English or French?

#include <stdio.h>

int n, s = 0, t = 0;
char c;
int main(){
    while ((n = getchar()) < 48);
    for (n -= 48; 48 <= (c = getchar()); n = (n << 3) + (n << 1) + c - 48);
    while (n--){
        while ((c = getchar()) != '\n'){
            if (c == 's' || c == 'S') s++;
            else if (c == 't' || c == 'T') t++;
        }
    }
    if (t <= s) puts("French");
    else puts("English");

    return 0;
}