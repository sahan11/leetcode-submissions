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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* ptr = head->next;
        ListNode*prev = head;
        vector<int> ans = {INT_MAX, -1};
        int min_cnt = 0;
        int prev_ind = -1;
        int min_ind = INT_MAX;
        int ind = 1;

        while(ptr->next != NULL) {
            if((ptr->val > prev->val && ptr->val > ptr->next->val) || (ptr->val < prev->val && ptr->val < ptr->next->val)) {
                cout<<ptr->val<<endl;
                if(min_ind == INT_MAX) {
                    min_ind = ind;
                }
                
                if(prev_ind != -1) {
                    ans[0] = min(ans[0], ind - prev_ind);
                    prev_ind = ind;
                }
                prev_ind = ind;


            }
            ind++;
            prev = prev->next;
            ptr = ptr->next;

        }
        if(min_ind != INT_MAX && min_ind != prev_ind) {
            ans[1] = prev_ind - min_ind;
            return ans;
        }
        return {-1, -1};
        
    }
};