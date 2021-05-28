// UCC Coding Competition '21 P4 - Trampoline Jump

#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << ": " << x << '\n'

int n, dis[(int)5e5+3];
deque<int> q = {1};
unordered_map<int, int> nums;
int fib(int num){
    if (num<=1) return 1;
    if (nums.find(num)!=nums.end()) return nums[num];
    nums[num] = (fib((num-1)/2)*fib((num-2)/2)+fib(num/2)*fib((num+1)/2))%2021;
    return nums[num];
}
int a(int num){
    return fib(num-1) + (num % 50);
}
int main(){
    cin >> n;
    // why is n changing
    int cpy = n;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();

        // next adjacent house
        if (cur + 1 <= n && dis[cur] + 1 < dis[cur+1]){
            dis[cur+1] = dis[cur] + 1;
            q.push_back(cur+1);
        }

        // prev adjacent house
        // is this even needed
        if (cur > 1 && dis[cur] + 1 < dis[cur-1]){
            dis[cur-1] = dis[cur] + 1;
            q.push_back(cur-1);
        }

        // move forward with jump
        int forward = a(cur);
        if (cur + forward <= n && dis[cur] + 1 < dis[cur+forward]){
            dis[cur+forward] = dis[cur] + 1;
            q.push_back(cur+forward);
        }

        // move backward with jump
        int backward = -forward;
        if (cur + backward > 1 && dis[cur] + 1 < dis[cur+backward]){
            dis[cur+backward] = dis[cur] + 1;
            q.push_back(cur+backward);
        }
    }
    printf("%d\n", dis[cpy]);

    return 0;
}