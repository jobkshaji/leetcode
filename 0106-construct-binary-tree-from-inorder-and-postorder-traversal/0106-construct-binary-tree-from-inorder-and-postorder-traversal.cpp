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
    TreeNode *fun(vector<int>& postorder, int & idx, unordered_map<int,int>&f,int l,int h){
        if(l>h) return nullptr;
        TreeNode * node= new TreeNode(postorder[idx--]);
        int id=f[node->val];
        node->right=fun(postorder,idx,f,id+1,h);
        node->left=fun(postorder,idx,f,l,id-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        unordered_map<int,int>f;
        for(int i=0;i<inorder.size();i++){
            f[inorder[i]]=i;
        }
        int l=0;
        int h=inorder.size()-1;
        return fun(postorder,idx,f,l,h);
    }
};