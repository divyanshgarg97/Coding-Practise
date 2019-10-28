//leetcode
//701.Insert into a Binary Search Tree
class Solution {
public:
    TreeNode * insert(TreeNode * root , int val) {
        if( root == NULL ){
            TreeNode * nodenew = new TreeNode (val) ;
            return nodenew;
        }
        
        if( root->val < val) {
            root->right = insert(root->right,val);
        }
        else if( root->val > val) {
            root->left = insert(root->left , val);
        }
        return root; 
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( root == NULL ) {
            root = new TreeNode(val);
            return root;
        }
        root = insert(root , val);
        return root; 
    }
};