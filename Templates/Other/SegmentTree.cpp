// Segment Tree Class

#include<bits/stdc++.h>
using namespace std;

const int MM = 1e5+3;
class SegTree{
    // O(4N) space complexity
    vector<int> seg;

    // build the segment tree
    void build(int cur, int l, int r, vector<int> const &arr){
        if (l == r) seg[cur] = arr[l];
        else {
            int mid = (l + r) / 2;
            build(cur*2, l, mid, arr); // build left node
            build(cur*2+1, mid+1, r, arr); // build right node
            seg[cur] = seg[cur*2] + seg[cur*2+1];
        }
    }

public:
    SegTree(vector<int> const &arr){
        cout << "begin init\n";
        seg.resize(4*(arr.size()+1));
        build(1, 1, arr.size()-1, arr);
    }


    void update_add(int cur, int l, int r, int ql, int qr, int val){
        // add val to each of arr[ql..qr]
        if (l > r) return;
        if (l == ql && r == qr) seg[cur] += val;
        else {
            int mid = (l + r) / 2;
            update_add(cur*2, l, mid, ql, min(qr, mid), val);
            update_add(cur*2+1, mid+1, r, max(ql, mid+1), qr, val);
        }
    }

    void update_set(int cur, int pos, int l, int r, int val){ // set arr[l..r] to val
        if (l == r) seg[cur] = val;
        else {
            int mid = (l + r) / 2;
            if (mid >= pos) // update left side
                update_set(cur*2, pos, l, mid, val);
            else // update right side
                update_set(cur*2+1, pos, mid+1, r, val);
        }
    }

    long long range_sum(int cur, int l, int r, int ql, int qr){
        // sum of arr[ql..qr]
        if (ql > qr) return 0;
        if (l == ql && r == qr) return seg[cur];
        int mid = (l + r) / 2;
        //     left side sum                                right side sum
        return range_sum(cur*2, l, mid, ql, min(qr, mid)) + range_sum(cur*2+1, mid+1, r, max(ql, mid+1), ql);
    }

    int range_max(int cur, int l, int r, int ql, int qr){
        // maximum of arr[ql..qr]
        if (ql > qr) return INT_MIN;
        if (l == ql && r == qr) return seg[cur];
        int mid = (l + r) / 2;
        //         left side max                               right side max
        return max(range_max(cur*2, l, mid, ql, min(qr, mid)), range_max(cur*2+1, mid+1, r, max(ql, mid+1), ql));
    }

    int range_min(int cur, int l, int r, int ql, int qr){
        // maximum of arr[ql..qr]
        if (ql > qr) return INT_MAX;
        if (l == ql && r == qr) return seg[cur];
        int mid = (l + r) / 2;
        //         left side min                               right side min
        return min(range_min(cur*2, l, mid, ql, min(qr, mid)), range_min(cur*2+1, mid+1, r, max(ql, mid+1), ql));
    }
    // gcd

};

vector<int> arr = {0, 1, 2, 3, 4, 5, 6};
int main(){
    SegTree test = SegTree(arr);
    cout << "done init\n";
    cout << test.range_sum(1, 1, 6, 2, 6);

    return 0;
}