/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* fun(TreeNode *root, TreeNode *p, TreeNode*q){
        if(root==nullptr) return root;
        if(root ==p || root ==q) return root;
        if(root->val<p->val) return fun(root->right,p,q);
        else if(root->val>q->val) return fun(root->left,p,q);
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val) return fun(root,p,q);
        else return fun(root,q,p);
    }
};