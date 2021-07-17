// BlueBook - Grades

#include<stdio.h>

int t, n;
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        char c = 'X';
        if (n > 100);
        else if (n >= 80) c = 'A';
        else if (n >= 70) c = 'B';
        else if (n >= 60) c = 'C';
        else if (n >= 50) c = 'D';
        else if (n >= 0) c = 'F';
        printf("%c\n", c);
    }

    return 0;
}