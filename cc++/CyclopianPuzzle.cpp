// Cyclopian Puzzle

#include<stdio.h>

int n;
void hanoi(int n, char start, char end, char tmp){
    if (n==1){
        printf("%c%c\n", start, end);
        return;
    }
    hanoi(n-1, start, tmp, end);
    printf("%c%c\n", start, end);
    hanoi(n-1, tmp, end, start);
}
int main(){
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}