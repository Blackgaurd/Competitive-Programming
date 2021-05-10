// Another Contest 7 Problem 1 - Lonely Users

#include<cstdio>

int n;
int main(){
    scanf("%d", &n);
    while (n--){
        int a; scanf("%d", &a);
        if (a == 2) a = 3;
        printf("%d\n", a - 1);
    }
    return 0;
}