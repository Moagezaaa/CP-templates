struct SegmentTree {
    int n;
    vector<ll> tree;
    
    SegmentTree(int size) {
        n = size;
        tree.resize(2 * n, 0);
    }
    
    void update(int idx, ll val) {
        idx += n;
        tree[idx] += val;
        for (idx /= 2; idx > 0; idx /= 2) {
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }
    
    ll query(int l, int r) {
        l += n;
        r += n;
        ll res = 0;
        while (l <= r) {
            if (l & 1) res = max(res, tree[l++]);
            if (!(r & 1)) res = max(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};
 