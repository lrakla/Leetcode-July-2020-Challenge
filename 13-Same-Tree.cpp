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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL) return true;
        if (p == NULL) return false; 
        if (q == NULL) return false;
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* p_curr = q1.front();
            TreeNode* q_curr = q2.front();
            if(p_curr->val != q_curr->val) return false;
            q1.pop(); q2.pop();
            
            if(p_curr->left && q_curr->left){
                q1.push(p_curr->left);
                q2.push(q_curr->left);
            }
            else if (p_curr->left || q_curr->left) return false;
            
            if(p_curr->right && q_curr->right){
                q1.push(p_curr->right);
                q2.push(q_curr->right);
            }
            else if (p_curr->right || q_curr->right) return false;               
            
        }
        return true;
        
    }
};