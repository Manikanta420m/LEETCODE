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
   vector<TreeNode*> buildTrees(int start,int end){
    if(start>end)return {nullptr};
    vector<TreeNode*>allTrees;
    for(int i=start;i<=end;i++){
        vector<TreeNode*>leftTrees=buildTrees( start, i-1);
        vector<TreeNode*>rightTrees=buildTrees( i+1, end);

        for(TreeNode* l:leftTrees){
            for(TreeNode* r:rightTrees){
               TreeNode *cur=new TreeNode(i);
               cur->left=l;
               cur->right=r;
               allTrees.push_back(cur);
            }
        }
    }
    return allTrees;
   }
public:
    vector<TreeNode*> generateTrees(int n) {
        return n?buildTrees(1,n):vector<TreeNode*>();
    }
};