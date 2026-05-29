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
    vector<int>tmp;
    void fun(TreeNode * root){
        if(root==nullptr) return;
        fun(root->left);
        tmp.push_back(root->val);
        fun(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        fun(root);
        return tmp[k-1];
    }
};