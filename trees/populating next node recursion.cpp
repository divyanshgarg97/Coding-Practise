class Solution {
public:
    //cannot use bfs as question itself has mentioned constant extra space must be used(we can use stack space , so RECURSION)
    //using Recursice level order right to left
    //first time when reach a level its next = NULL
    
    int height(Node* root){
        if( root == NULL){
            return 0 ; 
        }
        int l = height( root->left);
        int r = height(root->right) ; 
        return l > r ? l + 1: r + 1; 
    }
    void LOT ( Node * root) {
        if( root == NULL) {
            return ; 
        }
        Node * nextone = NULL; 
        for( int i = 1; i <=height(root) ;i++ ){
            level( root , i ,nextone);
            nextone = NULL; 
        }
    }
    void level(Node * root , int i , Node * &nextone) {
        if(root == NULL) 
            return ; 
        if( i == 1) {
            root->next = nextone; 
            nextone = root; 
            return;
        }
        else{
            level(root->right , i -1, nextone);
            level(root->left , i-1 , nextone);
        }
    }
    Node* connect(Node* root) {
        LOT(root);
        return root;
        
    }
};