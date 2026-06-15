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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)return NULL;
        if(head->next->next==NULL){
            head->next=head->next->next;
            return head;
        }
        ListNode *slow=head,*fast=head;
        while(fast ){
            if(fast->next->next==NULL){
                slow->next=slow->next->next;
                return head;
            }
            else{
                fast=fast->next->next;
                if(fast->next==NULL){
                    slow->next=slow->next->next;
                    return head;
                }
                slow=slow->next;
            }
        }
        return head;
    }
};