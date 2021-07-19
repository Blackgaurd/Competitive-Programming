// CCC '11 S3 - Alice Through the Looking Glass

#include<stdio.h>
#include<math.h>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int t;
int check(int m, int x, int y){
    int a = pow(5, m-1);

    if (a < x && x <= 4*a && y <= 2*a){
        if (y <= a || 2*a < x && x <= 3*a) return 1;
        if (m > 1){
            if (x > 3*a) return check(m-1, x-3*a, y-a);
            return check(m-1, x-a, y-a);
        }
    }
    else if (m > 1 && 2*a < x && x <= 3*a && 2*a < y && y <= 3*a)
        return check(m-1, x-2*a, y-2*a);

    return 0;
}
int main(){
    su(t);
    while (t--){
        int m, x, y; su(m); su(x); su(y);
        printf("%s\n", check(m, x+1, y+1)?"crystal":"empty");
    }
    return 0;
}