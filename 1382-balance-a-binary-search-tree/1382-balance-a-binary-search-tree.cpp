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
    void inorder(TreeNode* node,vector<int>&a){
        if(!node)return;
        inorder(node->left,a);
        a.push_back(node->val);
        inorder(node->right,a);
    }
    TreeNode* build(vector<int>&a,int l,int r){
        if(l>r)return NULL;
        int mid=l+(r-l)/2;
        TreeNode* node=new TreeNode(a[mid]);
        node->left=build(a,l,mid-1);
        node->right=build(a,mid+1,r);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>a;
        inorder(root,a);
        return build(a,0,a.size()-1);
    }
};