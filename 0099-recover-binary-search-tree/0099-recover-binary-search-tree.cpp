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
    int g=0;
    TreeNode * prev=nullptr;
    TreeNode * g1f=nullptr;
    TreeNode * g1s=nullptr;
    TreeNode * g2f=nullptr;
    TreeNode * g2s=nullptr;
    void fun(TreeNode * root){
        if(root==nullptr) return;
        fun(root->left);
        if(prev==nullptr) prev=root;
        else{
            if(root->val<prev->val){
                if(g==0){
                    g1f=prev;
                    g1s=root;
                    g++;
                }else{
                    g2f=prev;
                    g2s=root;
                    g++;
                }
            }
            prev=root;
        }
        fun(root->right);
    }
    void recoverTree(TreeNode* root) {
        fun(root);
        if(g==1){
            swap(g1f->val,g1s->val);
        }else{
            swap(g1f->val,g2s->val);
        }
    }
};