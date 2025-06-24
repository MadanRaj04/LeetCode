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

    void recur(TreeNode* root,int targetSum,vector<int>& path,vector<vector<int>>& res)
    {
        if(root == nullptr)
        {
            return;
        }
        path.push_back(root->val);
        targetSum-= root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(targetSum==0)
            {
                res.push_back(path);
            }
        }
        recur(root->left,targetSum,path,res);
        recur(root->right,targetSum,path,res);
        path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        recur(root,targetSum,path,res);
        return res;
    }
};