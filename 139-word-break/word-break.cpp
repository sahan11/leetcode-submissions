class Node{
    Node* link[26];
    bool flag = false;

    public:
    bool containsKey(char ch) {
        return (link[ch - 'a'] != NULL);
    }

    void insert(char ch, Node* node) {
        link[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return link[ch - 'a'];
    }

    void setFlag(){
        flag = 1;
    }

    bool getFlag() {
        return flag;
    }


};

class Trie {
    private: Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(string wd) {
        Node* node = root;
        for(int i = 0;i<wd.size();i++) {
            if(!node->containsKey(wd[i])) node->insert(wd[i], new Node());
            node = node->get(wd[i]);
        }
        node->setFlag();
    }

    bool search(string wd) {
        Node* node = root;
        for(int i = 0;i<wd.size();i++) {
            if(!node->containsKey(wd[i])) return 0;
            node = node->get(wd[i]);
        }
        return node->getFlag();
    }
};


class Solution {
public:
    bool f(int ind, Trie* t, string s, vector<int> &dp) {
        int n = s.size();
        if(ind == n) return true;
        if(dp[ind] != -1) return dp[ind];
        bool ans = false;
        for(int i = ind + 1;i<=n;i++){
            cout<<s.substr(ind, i - ind)<<endl;
            if(t->search(s.substr(ind, i - ind))){
                cout<<s.substr(ind, i - ind);
                ans = ans | f(i, t, s, dp);
            }
            if(ans) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, -1);
        int n = s.size();
        Trie* t = new Trie();
        for(auto it : wordDict) {
            t->insert(it);
        }
        
        return f(0, t, s, dp);
        
    }
};