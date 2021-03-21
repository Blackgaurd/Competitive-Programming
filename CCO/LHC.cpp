// CCO '13 P3 - LHC

#include<bits/stdc++.h>
using namespace std;
#define ms(arr, val) memset(arr, val, sizeof(arr))

// the idea is to find the ebdpoints which
// are the furthest away from the midpoint
//
// in the case where all such enpoints are of equal 
// length, count diagonals + sides (like a polygon)
//
// in the case where there are 2 lengths,
// multiply the number of endpoints of len1
// by those of len2
//
// the loop length is just the diameter

const int MM = 4e5+5;
int n, in[MM], dis[MM];
long long endpoints1 = 0, endpoints2 = 0;
vector<int> adj[MM];
pair<int, int> bfs(int start){ // find furthest node from start (and how far)
    deque<int> q;
    ms(dis, -1);
    dis[start] = 0; q.push_back(start);
    int ret, mxdis = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        if (dis[cur]>mxdis){
            mxdis = dis[cur];
            ret = cur;
        }
        for (int nxt: adj[cur]){
            if (dis[nxt]==-1){
                dis[nxt] = dis[cur]+1;
                q.push_back(nxt);
            }
        }
    }
    return {ret, mxdis};
}
int main(){
    scanf("%d", &n);
    for (int i=0; i<n-1; i++){
        int a, b; scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        in[a]++; in[b]++;
    }

    // find diameter (start from 1 to find a max point, run bfs again from that point)
    int e1 = bfs(1).first;
    int e2 = bfs(e1).first;
    int dia = bfs(e1).second;
    printf("end: %d, %d\n", e1, e2);
    printf("diameter: %d\n", dia);

    
    // find midpoint
    int mid;
    for (int i=1; i<=n; i++){
        if (dis[i]==dia/2){
            mid = i;
            break;
        }
    }
    
    // bfs from mid to find endpoints on either side
    deque<int> q;
    ms(dis, -1);
    dis[mid] = 0;
    q.push_back(mid);
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        if (in[cur]==1){
            if (dis[cur]==dia/2) endpoints1++;
            else if (dis[cur]==dia/2+1) endpoints2++;
        }
        for (int nxt: adj[cur]){
            if (dis[nxt]==-1){
                dis[nxt] = dis[cur]+1;
                q.push_back(nxt);
            }
        }
    }

    // calculate answer
    printf("%d %d\n", endpoints1, endpoints2);
    long long ans = (endpoints2? endpoints1*endpoints2 : (pow(endpoints1, 2)-endpoints1)/2);
    printf("%d %lld\n", dia+1, ans);
    // ans calculation is wrong
    
//7
//1 3
//1 4
//1 5
//1 2
//2 6
//2 7

    printf ("%d\n", mid);
    
    

    return 0;
}
