// IOI '01 P1 - Mobile Phones

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

template<typename T>
struct BIT2D{
    vector<vector<T>> bit;
    int n, m;

    BIT2D(int n, int m){
        this->n = n;
        this->m = m;
        bit.assign(n, vector<T>(m, 0));
    }

    BIT2D(vector<vector<int>> &arr) : BIT2D(arr.size(), arr[0].size()){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                add(i, j, arr[i][j]);
    }

    T sum(int x, int y) {
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }

    T sum(int x1, int y1, int x2, int y2){
        x1--; y1--;
        return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
    }
};


int s;
char c;
int main(){
    sc(c); su(s);
    BIT2D<int> bit(s, s);
    do {
        sc(c);
        if (c == '1'){
            int x, y, a;
            su(x); su(y); si(a);
            bit.add(x, y, a);
        }
        else if (c == '2'){
            int l, b, r, t;
            su(l); su(b); su(r); su(t);
            printf("%d\n", bit.sum(l, b, r, t));
        }
    } while (c != '3');

    return 0;
}