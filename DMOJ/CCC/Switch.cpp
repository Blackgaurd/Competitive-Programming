// CCC '11 S5 - Switch

#include<cstdio>
#include<deque>
#include<string.h>
using namespace std;

int k, start = 0;
char dis[1<<25];
deque<int> q;
int turn(int mask, int ind){
    // mask |= (1 << ind);
    int l = ind, r = ind;
    do{l++;}while(mask & (1 << l));
    do{r--;}while(mask & (1 << r));
    l--; r++;
    if (l-r+1 >= 4)
        mask = ~(~mask | (((1 << (l-r+1))-1) << r));

    return mask;
}
int main(){
    scanf("%d", &k);
    for (int i=0, a; i<k; i++){
        start <<= 1;
        scanf("%d", &a);
        start |= a;
    }
    for (int i=0; i<k; i++){
        if (start & (1 << i)){
            start = turn(start, i);
        }
    }
    q.push_back(start);
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[start] = 0;
    while (!q.empty()){
        int mask = q.front();
        q.pop_front();
        if (!mask) continue;
        for (int i=0; i<k; i++){
            if (!(mask & (1 << i)) && (mask & (1 << i-1) || mask & (1 << i+1))){
                int newmask = turn(mask | (1 << i), i);
                if (dis[mask] + 1 < dis[newmask]){
                    dis[newmask] = dis[mask] + 1;
                    q.push_back(newmask);
                }
            }
        }
    }
    printf("%d\n", (int)dis[0]);

    return 0;
}