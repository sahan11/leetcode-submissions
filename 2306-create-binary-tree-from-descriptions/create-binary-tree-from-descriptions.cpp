/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findUlp(map<int, int> &ulp, int node) {
        if(ulp.find(node) == ulp.end()) {
            return node;
        }
        return findUlp(ulp, ulp[node]);
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int, TreeNode*> mp;
        map<int, int> ulp;
        int curPar = -1;
        int n = d.size();
        for(int i = 0;i<n;i++) {
            TreeNode* par;
            TreeNode* child;
            int from = d[i][0];
            int to = d[i][1];
            ulp[to] = from;
            if(mp.find(to) == mp.end()) {
                child = new TreeNode(to);
                mp[to] = child;
            }
            else {
                child = mp[to];
            }
            if(mp.find(from) == mp.end()) {
                par = new TreeNode(from);
                mp[from] = par;
            }
            else {
                par = mp[from];
            }
            if(d[i][2]) {
                par->left = child;
            }
            else par->right = child;

        }
        return mp[findUlp(ulp, d[0][0])];
    }
};