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
    pair<int, ListNode*> calcSum(ListNode* root) {
        int sum = 0;
        while(root != NULL && root->val != 0) {
            sum+=root->val;
            root = root->next;
        }
        return {sum, root};
    }
    
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root = new ListNode(0);
        // return root;
        ListNode* ptr = root;
        ListNode* curptr = head;
        while(curptr != NULL) {
            if(curptr->next == NULL) break;
            if(curptr->val == 0) {
                pair<int, ListNode*> data = calcSum(curptr->next);
                ListNode* newNode = new ListNode(data.first);
                curptr = data.second;
                ptr->next = newNode;
                ptr = ptr->next;
                
            }
            if(curptr == NULL) break;
            // curptr = curptr->next;
        }
        return root->next;
    }
};