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
        if(root == nullptr){
            return {};
        }
        bool l2r=1;
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int first=0;
            int last=s-1;
            vector<int>tmp(s);
            while(s--){
                TreeNode*t=q.front();
                q.pop();
                if(l2r==1){
                    tmp[first]=t->val;
                    first++;
                }else{
                    tmp[last]=t->val;
                    last--;
                }
                if(t->left!=nullptr) q.push(t->left);
                if(t->right!=nullptr) q.push(t->right);
            }
            res.push_back(tmp);
            l2r=1-l2r;
        }
        return res;
    }
};