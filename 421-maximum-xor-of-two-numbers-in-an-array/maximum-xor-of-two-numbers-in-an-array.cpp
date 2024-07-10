struct Node {
    Node* link[2];

    bool containsKey(int ind) {
        return (link[ind] != NULL);
    }

    void put(int ind, Node* node) {
        link[ind] = node;
    }

    Node* get(int ind) {
        return link[ind];
    }
};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }

        void insert(int ind) {
            Node* node = root;
            for(int i = 31;i>=0;i--) {
                int bit = (ind >> i) & 1;
                if(!node->containsKey(bit)) {
                    node->put(bit, new Node());
                } 
                node = node->get(bit);
            }
        }

        int maxXor(int ind) {
            Node* node = root;
            int sum = 0;
            for(int i = 31;i>=0;i--) {
                int bit = (ind >> i) & 1;
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
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        for(int i = 0;i<nums.size();i++) {
            t->insert(nums[i]);
        }

        cout<<"insert done";

        int ans = INT_MIN;
        for(int i = 0;i<nums.size();i++) {
            cout<<("in loop");
            ans = max(ans, t->maxXor(nums[i]));
        }

        return ans;
    }
};