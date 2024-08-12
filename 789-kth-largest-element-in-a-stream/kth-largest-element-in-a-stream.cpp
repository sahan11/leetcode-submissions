class KthLargest {
public:
    vector<int> stream;
    int pos;
    KthLargest(int k, vector<int>& nums) {
        pos = k;
        for(auto it : nums) {
            auto inPos = lower_bound(stream.begin(), stream.end(), it);
            stream.insert(inPos, it);
        }
    }
    
    int add(int val) {
        auto inPos = lower_bound(stream.begin(), stream.end(), val);
        stream.insert(inPos, val);
        return stream[stream.size() - pos];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */