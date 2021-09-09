// Another Sorting

#include<cstdio>
#include<algorithm>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n, arr[100000];
bool comp(int a, int b){
    if (a%10 != b%10)
        return a%10 < b%10;
    return a > b;
}
int main(){
    su(n);
    for (int i=0; i<n; i++) su(arr[i]);
    sort(arr, arr+n, comp);
    for (int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}