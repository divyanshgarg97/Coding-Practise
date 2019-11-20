/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<TreeNode* , int>  height(TreeNode * root) {
        if( root == NULL) 
            return {root , 0} ; 
        pair<TreeNode * , int >  l = height( root->left); 
        pair<TreeNode * , int> r  = height(root->right); 
        if( l.second == r.second){
            return {root,l.second + 1 };
        }
        else if( l.second > r.second){
            return {l.first , l.second + 1 };
        }
        else
            return {r.first , r.second+ 1 };
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto ans = height(root); 
        return ans.first;
        
    }
};