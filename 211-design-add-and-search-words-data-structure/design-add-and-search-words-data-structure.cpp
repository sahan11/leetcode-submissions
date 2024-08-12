class Node {
    Node* link[26];
    int flag = false;

    public: bool containsKey(char ch) {
        return (link[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        link[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return link[ch - 'a'];
    }

    void setFlag() {
        flag = true;
    }

    bool getFlag() {
        return flag;
    }
};

class Trie {
    private : Node* root;
    public:
    
    Trie() {
        root = new Node();
    }

    void insert(string wd) {
        Node* node = root;
        for(int i = 0;i<wd.size();i++) {
            if(!node->containsKey(wd[i])) node->put(wd[i], new Node());
            node = node->get(wd[i]);
        }
        node->setFlag();
    }

    bool search(string wd, Node* node = NULL) {
        if(node == NULL) node = root;
        for(int i = 0;i<wd.size();i++) {
            if(wd[i] == '.') {
                bool ans = false;
                for(int j = 0;j<26;j++) {
                    if(node->containsKey('a' + j)) {
                        ans = ans | search(char('a' + j) + wd.substr(i + 1), node);
                        if(ans) return true;
                    }
                }
                return false;
            }
            else {
                if(!node->containsKey(wd[i])) return false;
                node = node->get(wd[i]);
            }
            
        }
        return node->getFlag();
    }
};


class WordDictionary {
public:
    Trie* t;
    WordDictionary() {
        t = new Trie();
    }
    
    void addWord(string word) {
        t->insert(word);
    }
    
    bool search(string word) {
        return t->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */