// CCC '08 J3 - GPS Text Entry

#include<stdio.h>
#include<math.h>

char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ -.\n", c;
int ans = 0, x = 0, y = 0;
int find(char cur){
    for (int i=0; i<30; i++)
        if (chars[i] == cur) return i;
    return -1;
}
int main(){
    while ((c = getchar()) != EOF){
        int pos = find(c);
        int nx = pos % 6, ny = pos / 6;
        ans += abs(x - nx) + abs(y - ny);
        x = nx;
        y = ny;
    }
    printf("%d\n", ans);
}