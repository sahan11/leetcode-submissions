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
    void f(int num, TreeNode* root, int &sum){
        if(root->left == NULL && root->right == NULL) {
            sum += num*10 + root->val;
            return;
        }

        num = num*10 + root->val;
        if(root->left != NULL) f(num, root->left, sum);
        if(root->right != NULL) f(num, root->right, sum);

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        f(0, root, sum);
        return sum;
    }
};