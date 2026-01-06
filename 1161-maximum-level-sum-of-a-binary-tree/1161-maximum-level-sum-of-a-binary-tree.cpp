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
    int maxLevelSum(TreeNode* root) {
        int ans=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int res=0,i=1,idx=1;
        while(!q.empty()){
            int n=q.size();
            res=0;
            for(int i=0;i<n;i++){
                TreeNode *ele=q.front();
                q.pop();
                res+=ele->val;
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            if(res>ans){
                idx=i;
                ans=res;
            }
            i++;
        }
        return idx;
    }
};