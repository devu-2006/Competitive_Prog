#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> seg;
    int n;

    void build(int ind, int low, int high, const vector<int>& a) {
        if (low == high) {
            seg[ind] = a[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2*ind+1, low, mid, a);
        build(2*ind+2, mid+1, high, a);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if (r < low || high < l) return INT_MAX;
        if (l <= low && high <= r) return seg[ind];
        int mid = low + (high - low) / 2;
        return min(
            query(2*ind+1, low, mid, l, r),
            query(2*ind+2, mid+1, high, l, r)
        );
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        seg.resize(4*n);
        build(0, 0, n-1, a);
    }

    int rangeMin(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    void pointUpdate(int i, int val) {
        update(0, 0, n-1, i, val);
    }
};


int main(){

    return 0;
}