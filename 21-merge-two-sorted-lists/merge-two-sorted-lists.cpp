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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* ptr = new ListNode();
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val < list2->val){
            ptr->val = list1->val;
            list1 = list1->next;
        }
        else{
            ptr->val = list2->val;
            list2 = list2->next;
        }
        head = ptr;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                ListNode* temp = new ListNode(list1->val);
                ptr->next = temp;
                ptr = ptr->next;
                list1 = list1->next;
            }
            else{
                ListNode* temp = new ListNode(list2->val);
                ptr->next = temp;
                ptr = ptr->next;
                list2 = list2->next;
            }
        }

        while(list1 != NULL){
            ListNode* temp = new ListNode(list1->val);
            ptr->next = temp;
            ptr = ptr->next;
            list1 = list1->next;
        }

        while(list2 != NULL){
            ListNode* temp = new ListNode(list2->val);
            ptr->next = temp;
            ptr = ptr->next;
            list2 = list2->next;
        }
        return head;
    }
};