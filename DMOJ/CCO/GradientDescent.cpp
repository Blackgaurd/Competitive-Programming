// CCO '18 P4 - Gradient Descent

#include<stdio.h>
#include<unordered_map>

int r, c, k;
std::unordered_map<long long, int> mp;
int query(int x, int y){
    int key = x * 100000000 + y;
    if (mp.count(key)) return mp[key];
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int val;
    scanf("%d", &val);
    mp.insert({key, val});
    return val;
}
int main(){
    scanf("%d%d%d", &r, &c, &k);
    int rlo = 1, rhi = r, clo = 1, chi = c;
    while (rlo < rhi || clo < chi){
        int rmid = (rlo + rhi)/2, cmid = (clo + chi)/2;
        if (rlo < rhi){
            int center = query(rmid, cmid), below = query(rmid + 1, cmid);
            if (center < below) rhi = rmid;
            else rlo = rmid + 1;
        }
        if (clo < chi){
            int center = query(rmid, cmid), right = query(rmid, cmid + 1);
            if (center < right) chi = cmid;
            else clo = cmid + 1;
        }
    }
    printf("! %d\n", query(rlo, clo));
    fflush(stdout);

    return 0;
}