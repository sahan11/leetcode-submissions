struct Node {
    Node* link[26];
    bool flag = 0;

    bool containsKey(char ch) {
        return (link[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        link[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return link[ch - 'a'];
    }

    void setEnd() {
        flag = true;
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

        void insert(string word) {
            Node* node = root;
            for(int i = 0;i<word.size();i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            } 
            node->setEnd();
        }

        string prefixReturn(string word) {
            Node* node = root;
            string str = "";
            for(int i = 0;i<word.size();i++) {
                if(node->getFlag()) {
                    return str;
                }
                if(!node->containsKey(word[i])) {
                    return word;
                }
                else {
                    node = node->get(word[i]);
                    str = str + word[i];
                }
            }
            return str;
        }
};



class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string sen = "";
        Trie* t = new Trie();
        for(int i = 0;i<dictionary.size();i++) {
            t->insert(dictionary[i]);
        }
        string wd = "";
        for(int i = 0;i<sentence.size();i++) {
            if(sentence[i] == ' ') {
                sen += t->prefixReturn(wd) + " ";
                wd = "";
                continue;
            }
            else {
                wd += sentence[i];
            }
        }
        sen += t->prefixReturn(wd);
        return sen;
    }
};