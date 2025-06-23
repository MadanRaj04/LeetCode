/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <unordered_map>

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> temp;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            if(t->left != nullptr)
            {
                temp[t->left] = t;
                q.push(t->left);
            }
            if(t->right != nullptr)
            {
                temp[t->right] = t;
                q.push(t->right);
            }
        }
        
        q.push(target);
        unordered_map<TreeNode*,int> visited;
        while(k > 0 && !q.empty())
        {
            int sz = q.size();
            for (int i=0;i<sz;i++)
            {
            t = q.front();
            q.pop();
            visited[t] = 0;
            if(t->left != nullptr && visited.find(t->left) == visited.end())
            {
                q.push(t->left);
            }
            if(t->right != nullptr && visited.find(t->right) == visited.end())
            {
                q.push(t->right);
            }
            if (temp.find(t) != temp.end() && visited.find(temp[t]) == visited.end()) {
                q.push(temp[t]);
            }

            }
            k-=1;

        }

        while (!q.empty())
        {
            t = q.front();
            q.pop();
            ans.push_back(t->val);
        }
        return ans;
    }
};