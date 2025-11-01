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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>mp(nums.begin(),nums.end());
        while(head and mp.count(head->val))head=head->next;
        ListNode *temp=head;
        while(temp and temp->next){
            while(temp->next and mp.count(temp->next->val))temp->next=temp->next->next;
            temp=temp->next;
        }
        return head;
    }
};