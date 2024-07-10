
struct Node {
    Node* link[2];

    bool containsKey(int bit) {
        return (link[bit] != NULL);
    }

    void put(int bit, Node* node) {
        link[bit] = node;
    }

    Node* get(int bit) {
        return link[bit];
    }
};

class Trie {
    private: Node* root;
    public: 
    Trie() {
        root = new Node();
    }

    void insert(int n) {
        Node* node = root;
        for(int i = 31;i>=0;i--) {
            int bit = (n >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }

    }

    int maxXor(int n, int maxVal) {
        Node* node = root;
        if(!node->containsKey(0) && !node->containsKey(1)) return -1;
        int num = 0;
        int sum = 0;
        for(int i = 31;i>=0;i--) {
            int bit = (n >> i) & 1;
            
            if(node->containsKey(1 - bit)) {
                sum += 1 << i;
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
            
            
        }
        return sum;
    }


};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* t = new Trie();
        int mini = INT_MAX;
        vector<vector<int>> q;
        vector<int> ans(queries.size(), 0);
        for(int i = 0;i<queries.size();i++) {
            q.push_back({queries[i][1], queries[i][0], i});
        }

        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        int j = 0;
        for(int i = 0;i<q.size();i++) {
            int x = q[i][1];
            int threshold = q[i][0];
            int ind = q[i][2];
            while(j < nums.size() && nums[j] <= threshold) {
                t->insert(nums[j]);
                j++;
            }
            ans[ind] = t->maxXor(x, threshold);
        }


        return ans;
    }
};