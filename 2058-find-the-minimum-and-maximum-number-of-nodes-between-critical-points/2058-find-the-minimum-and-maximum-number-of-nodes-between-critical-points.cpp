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
        vector<int>ans(2,-1);
        ListNode *temp = head,*prev=NULL;
        int mini=INT_MAX;
        int cnt1=-1,pre=0,cur=0,i=0;
        while(temp->next){
            if(prev){
               if(prev->val<temp->val and temp->val>temp->next->val){
                 if(cnt1==-1)cnt1=i;
                 pre=cur;
                 cur=i;
               }
               if(prev->val>temp->val and temp->val<temp->next->val){
                 if(cnt1==-1)cnt1=i;
                 pre=cur;
                 cur=i;
               }
            }
            if(pre!=0) mini=min(mini,cur-pre);
            i++;
            prev=temp;
            temp=temp->next;
        }
        if(mini==INT_MAX)return ans;
        ans[0]=(mini==INT_MAX?-1:mini);
        ans[1]=cur-cnt1;
        return ans;
    }
};