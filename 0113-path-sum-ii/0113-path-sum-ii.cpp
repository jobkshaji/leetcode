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
    vector<vector<int>>res;
    void fun(TreeNode*root,int sum,int targetSum,vector<int>diary){
        if(root==nullptr) return;
        sum+=root->val;
        diary.push_back(root->val);
        if(root->left ==nullptr && root->right==nullptr){
            if(sum==targetSum){
                res.push_back(diary);
                diary.pop_back();
                return;
            }else{
                diary.pop_back();
            }
        }
        fun(root->left,sum,targetSum,diary);
        fun(root->right,sum,targetSum,diary);
        return;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>diary;
        int sum=0;
        fun(root,sum,targetSum,diary);
        return res;
    }
};