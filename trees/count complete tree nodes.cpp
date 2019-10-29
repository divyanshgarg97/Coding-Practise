
class Solution {
public:
    int heightleft(TreeNode* root ) {
        if( root == NULL)
            return 0 ;
        int h = 1;
        while(root!=NULL){
            root = root->left;
            h++;
        }
        return h;
    }
    int heightright(TreeNode * root) {
        if( root ==NULL)
            return 0 ;
        int h = 1 ;
        while(root!=NULL){
            root = root->right; 
            h++ ;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if( root == NULL ) 
            return 0 ;
        int left = heightleft( root->left); 
        int right = heightright(root->right);
        if( left == right && left !=0) {
            return (2 << (left -1 )) - 1;    
        }
        return countNodes(root->left ) + countNodes(root->right) + 1; 
        
    }
};