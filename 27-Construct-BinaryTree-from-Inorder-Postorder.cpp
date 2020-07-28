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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,int i1,int i2,int p1, int p2){
        if(i1>=i2 || p1>=p2) return nullptr;
        TreeNode* root = new TreeNode(postorder[p2-1]);
        auto it = find(inorder.begin()+i1, inorder.end()+i2, postorder[p2-1]);
        int idx = it - inorder.begin() - i1;
        root->left = buildTree(inorder, postorder,i1, i1+idx, p1, p1+idx);
        root->right = buildTree(inorder, postorder,i1+idx + 1, i2, p1+idx, p2-1);
        return root;     
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0) return nullptr;
        return buildTree(inorder, postorder,0,n,0,n);
    }
};