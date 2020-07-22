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
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag= 0; //acts as flag for left to right or vice versa
        while(!q.empty()){  
            int s = q.size();
            vector<int> curr(s);
            for(int i=0; i<s; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(!flag){ //insert left to right
                    curr[i] = tmp->val;
                }
                else{       //insert right to left
                    curr[s-1-i] = tmp->val;
                }
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                
            }
            ans.push_back(curr);
            flag = !flag;
        }
        return ans;
        
        
    }
};