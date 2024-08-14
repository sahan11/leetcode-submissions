class SegmentTree {
    private:
    vector<int> seg;
    vector<int> A;
    vector<int> lazy;

    public:
    SegmentTree(int n, vector<int> &nums) {
        A = nums;
        seg.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        fillTree(0, n - 1, 0);
    }

    void fillTree(int low, int high, int ind) {
        if(low == high) {
            seg[ind] = A[low];
            return;
        }

        int mid = (low + high) >> 1;
        fillTree(low, mid, 2*ind + 1);
        fillTree(mid + 1, high, 2*ind + 2);
        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }

    void pointUpdate(int low, int high, int ind, int val, int pos) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if(mid >= pos && pos >= low) pointUpdate(low, mid, 2*ind + 1, val, pos);
        else pointUpdate(mid + 1, high, 2*ind + 2, val, pos);

        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];

    }

    int querySum(int low, int high, int l, int r, int ind) {
        if(low >= l && high <= r) {
            return seg[ind];
        }

        if(low > r || high < l) return 0;

        int mid = (low + high) >> 1;
        return querySum(low, mid, l, r, 2*ind + 1) + querySum(mid + 1, high, l, r, 2*ind + 2);


    }
    // void display() {
    //     for(int i = 0;i<A.size();i++) {
    //         cout<<A[i]<<' ';
    //     }cout<<'\n';
    //     for(int i = 0;i<seg.size();i++) {
    //         cout<<seg[i]<<' ';
    //     }cout<<'\n';
    // }


};

class NumArray {
public:
    SegmentTree* st;
    vector<int> A;
    NumArray(vector<int>& nums) {
        vector<int> seg;
        int n = nums.size();
        A = nums;
        seg.resize(4*n, 0);
        st = new SegmentTree(n, A);
        // st->display();
        cout<<st->querySum(0, n - 1, 0, 1, 0)<<'\n';
    }
    
    void update(int index, int val) {
        st->pointUpdate(0, A.size() - 1, 0, val, index);
        // st->display();
    }
    
    int sumRange(int left, int right) {
        return st->querySum(0, A.size() - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */