// DMOPC '14 Contest 2 P6 - Selective Cutting

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
struct BIT{
    vector<T> bit;
    int n;

    BIT(int size){
        n = size;
        bit.assign(n, 0);
    }

    BIT(vector<T> &arr) : BIT(arr.size()){
        for (int i=0; i<n; i++){
            add(i, arr[i]);
        }
    }

    void add(int ind, T val){
        while (ind < n){
            bit[ind] += val;
            ind |= (ind + 1);
        }
    }

    T get(int ind){
        if ((ind & 1) == 0)
            return bit[ind];
        return sum(ind, ind);
    }

    void set(int ind, T val){
        add(ind, val - get(ind));
    }

    T sum(int r){
        T ret = 0;
        while (r >= 0){
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }

    T sum(int l, int r){
        if (l <= 0)
            return sum(r);
        return sum(r) - sum(l-1);
    }
};

int n, q;
int main(){
    
}