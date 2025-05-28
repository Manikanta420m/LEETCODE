// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// private:
//     void solve(int cur,TreeNode *node,int target,vector<int>&res,vector<vector<int>>&ans){
//         if(node==NULL)return;
//         res.push_back(node->val);
//         cur+=node->val;
//         if(node->left==NULL and node->right==NULL){
//             if(cur==target)ans.push_back(res);
//         }
//         solve(cur,node->left,target,res,ans);
//         solve(cur,node->right,target,res,ans);
//         res.pop_back();
//         cur-=node->val;
//     }
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>>ans;
//         vector<int>res;
//         solve(0,root,targetSum,res,ans);
//         return ans;
//     }
// };
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
   void solve(TreeNode* root,int k,vector<vector<int>> &path,int sum,vector<int> a){
    if (root==NULL)
    {
        return;
    }
    sum+=root->val; 
    a.push_back(root->val);  

    if(root->left==NULL && root->right==NULL){
    if (sum==k)
    {
        path.push_back(a);
    }
    }

    solve(root->left,k,path,sum,a);
    solve(root->right,k,path,sum,a);
    
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

vector<vector<int>> path;
vector<int> a;
int sum=0;
solve(root,targetSum,path,sum,a);

return path;        
}
};