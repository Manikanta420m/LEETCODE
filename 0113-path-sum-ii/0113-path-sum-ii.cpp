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
private:
    void solve(int cur,TreeNode *node,int target,vector<int>&res,vector<vector<int>>&ans){
        if(node==NULL)return;
        res.push_back(node->val);
        cur+=node->val;
        if(node->left==NULL and node->right==NULL){
            if(cur==target)ans.push_back(res);
        }
        solve(cur,node->left,target,res,ans);
        solve(cur,node->right,target,res,ans);
        res.pop_back();
        cur-=node->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(0,root,targetSum,res,ans);
        return ans;
    }
};