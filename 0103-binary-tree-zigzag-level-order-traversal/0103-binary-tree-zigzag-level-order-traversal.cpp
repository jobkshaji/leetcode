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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return{};
        bool lefttoright=1;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty()){
            int size=q.size();
            vector<int>tmp(size);
            int f=0;
            int l=size-1;
            while(size--){
                TreeNode * t=q.front();
                q.pop();
                if(lefttoright==1){
                    tmp[f]=t->val;
                    f++;
                }else{
                    tmp[l]=t->val;
                    l--;
                }
                if(t->left!=nullptr) q.push(t->left);
                if(t->right!=nullptr) q.push(t->right);
            }
            res.push_back(tmp);
            lefttoright=1-lefttoright;
        }
        return res;
    }
};