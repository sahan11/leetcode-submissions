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
    TreeNode* f(TreeNode* root, vector<TreeNode*> &ans, vector<int> &t) {
        if(binary_search(t.begin(), t.end(), root->val)) {
            if(root->left != NULL) {
                TreeNode* temp = f(root->left, ans, t);
                if(temp != NULL) ans.push_back(temp);
                else root->left = NULL;

            }
            if(root->right != NULL) {
                TreeNode* temp = f(root->right, ans, t);
                if(temp != NULL) ans.push_back(temp);
                else root->right = NULL;
            }
            return NULL;
        }
        else {
            if(root->left != NULL) {
                TreeNode* temp = f(root->left, ans, t);
                if(temp == NULL) root->left = NULL;
            }
            if(root->right != NULL) {
                TreeNode* temp = f(root->right, ans, t);
                if(temp == NULL) root->right = NULL;
            }
            return root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& t) {
        sort(t.begin(), t.end());
        vector<TreeNode*> ans;
        TreeNode* temp = f(root, ans, t);
        if(temp != NULL) ans.push_back(root);
        return ans; 


    }
};