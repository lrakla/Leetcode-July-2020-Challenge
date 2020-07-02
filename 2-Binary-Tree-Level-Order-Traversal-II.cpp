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
vector<vector<int>> ans;
public:
    void dfs(TreeNode* root,int level){
        if(root==NULL) return;
        if(level == ans.size()){ //if level is size of ans, add new block of vector in ans
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        dfs(root->left,level+1); //go to next level
        dfs(root->right,level+1);
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root,0);
        return vector<vector<int>>(ans.rbegin(),ans.rend());     
    }
};