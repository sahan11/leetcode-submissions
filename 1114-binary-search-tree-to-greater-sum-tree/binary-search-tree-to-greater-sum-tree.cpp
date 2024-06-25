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
    int curSum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* r = bstToGst(root->right);
        int temp = root->val;
        root->val = root->val + curSum;
        curSum += temp;
        
        TreeNode* l = bstToGst(root->left);
        return root;
    }
};