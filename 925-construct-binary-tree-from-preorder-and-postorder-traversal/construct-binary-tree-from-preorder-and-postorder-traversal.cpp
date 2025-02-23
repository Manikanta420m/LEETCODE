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
    int pre=0,pos=0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* cur=new TreeNode(preorder[pre]);
        pre++;
        if(cur->val!=postorder[pos])
        cur->left=constructFromPrePost(preorder,postorder);
         if(cur->val!=postorder[pos])
        cur->right=constructFromPrePost(preorder,postorder);
        pos++;
        return cur;
    }
};