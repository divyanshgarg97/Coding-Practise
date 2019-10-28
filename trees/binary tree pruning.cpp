//814. Binary Tree Pruning
class Solution {
public:
    bool go( TreeNode * root ) {
        if( root == NULL ) 
            return false;
        bool l = go(root->left ) ; 
        bool r = go( root ->right) ; 
        if( l == false ) 
            root ->left = NULL; 
        if( r == false) 
            root->right = NULL ; 
        return root->val || l || r; 
    }
    TreeNode* pruneTree(TreeNode* root) {
        if( root == NULL ) 
            return root; 
        bool temp = go( root ) ;
        return root;
    }
};