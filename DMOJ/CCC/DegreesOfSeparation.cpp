// CCC '09 S3 - Degrees Of Separation

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 50;
bool adj[MM][MM];
char c;
int x, y, dis[MM];
void add(int a, int b){
    adj[a][b] = adj[b][a] = true;
}
void del(int a, int b){
    adj[a][b] = adj[b][a] = false;
}
int main(){
    add(2, 6);
    add(1, 6);
    add(6, 3);
    add(6, 4);
    add(6, 5);
    add(6, 7);
    add(3, 4);
    add(4, 5);
    add(7, 8);
    add(3, 5);
    add(8, 9);
    add(9, 10);
    add(9, 12);
    add(11, 10);
    add(11, 12);
    add(3, 15);
    add(13, 15);
    add(12, 13);
    add(13, 14);
    add(16, 17);
    add(17, 18);
    add(16, 18);
    while (true){
        sc(c);
        if (c == 'i'){
            su(x); su(y);
            add(x, y);
        }
        else if (c == 'd'){
            su(x); su(y);
            del(x, y);
        }
        else if (c == 'n'){
            su(x);
            int cnt = 0;
            for (int i=1; i<MM; i++)
                cnt += adj[x][i];
            printf("%d\n", cnt);
        }
        else if (c == 'f'){
            su(x);
            memset(dis, -1, sizeof(dis));
            dis[x] = 0;
            deque<int> q = {x};
            while (!q.empty()){
                int cur = q.front();
                q.pop_front();
                for (int i=1; i<MM; i++){
                    if (adj[cur][i] && dis[i] == -1){
                        dis[i] = dis[cur] + 1;
                        q.push_back(i);
                    }
                }
            }
            int cnt = 0;
            for (int i=1; i<MM; i++)
                if (dis[i] == 2) cnt++;
            printf("%d\n", cnt);
        }
        else if (c == 's'){
            memset(dis, -1, sizeof(dis));
            su(x); su(y);
            dis[x] = 0;
            deque<int> q = {x};
            while (!q.empty()){
                int cur = q.front();
                q.pop_front();
                for (int i=1; i<MM; i++){
                    if (adj[cur][i] && dis[i] == -1){
                        dis[i] = dis[cur] + 1;
                        q.push_back(i);
                    }
                }
            }
            if (dis[y] == -1)
                printf("Not connected\n");
            else printf("%d\n", dis[y]);
        }
        else break;
    }

    return 0;
}