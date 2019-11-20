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
    int go( TreeNode * root , int &ans){
        if (root == NULL ) {
            return 0 ; 
        }
        int left = go(root->left,ans) ;
        int right = go(root->right,ans); 
        ans += abs(left) + abs(right);// number of moves for both left and right;
        return root->val + right + left  - 1; 
    }
    int distributeCoins(TreeNode * root){
        if( root == NULL) 
            return 0 ; 
        int ans = 0 ; 
        int temp = go(root, ans) ;
        return ans;  
    }  
    
};