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
    unordered_map<int,int>f;
    int idx=0;
    TreeNode * fun(vector<int> & preorder , int l,int h){
        if(l>h) return nullptr;
        TreeNode * node =new TreeNode(preorder[idx]);
        idx++;
        int id=f[node->val];
        node->left=fun(preorder,l,id-1);
        node->right=fun(preorder,id+1,h);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            f[inorder[i]]=i;
        }
        int l=0;
        int h=inorder.size()-1; /** to only look l->high in inorder at a time**/ 
        return fun(preorder,l,h);
    }
};