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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root==NULL) return 0;
        int width =1;
        q.push(make_pair(root,0));
        while(!q.empty()){
            int count = q.size();
            int left_index = q.front().second;
            int right_index = q.back().second;
            width = max(width,right_index-left_index+1);
            for(int i=0;i<count;i++){
                pair<TreeNode*,int> p = q.front();
                int idx = p.second-left_index;
                q.pop();
                if(p.first->left) q.push({p.first->left,2*idx+1});
                if(p.first->right) q.push({p.first->right,2*idx+2});
                
            }
        }
        return width;
        
        
    }
};