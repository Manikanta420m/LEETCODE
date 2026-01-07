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
    const int M=1e9+7;
    long long ans=INT_MIN,tot=0;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int sum=root->val+dfs(root->left)+dfs(root->right);
        ans=max(ans,(tot-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        tot=dfs(root);
        dfs(root);
        return ans%M;
    }
};