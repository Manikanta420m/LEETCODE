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
 int leni(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    int cnt=0;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        cnt++;
    }
    if(fast)cnt++;
    return cnt;
 }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)return head;
        int len=1;
        ListNode* tail=head;
        while(tail->next){
            len++;
            tail=tail->next;
        }
        if(k>len){k%=len;
        if(k==0)return head;}
        if(k<=len){
            k=len-k;
            if(k==0)return head;
        }
        int cnt=1;
        ListNode* curr=head;
        while(cnt<k&&curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        ListNode* temp=curr->next;
        curr->next=NULL;
        tail->next=head;
        return temp;
        
    }
};