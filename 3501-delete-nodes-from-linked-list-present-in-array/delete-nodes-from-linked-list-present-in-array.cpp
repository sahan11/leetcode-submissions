/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* node, vector<int> &nums) {
        if(node == NULL) return node;
        if(binary_search(nums.begin(), nums.end(), node->val)) {
            return deleteNode(node->next, nums);
        }
        else {
            ListNode* temp = deleteNode(node->next, nums);
            node->next = temp;
            return node;
        }
    }
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        ListNode* node = deleteNode(head, nums);
        return node;
    }
};