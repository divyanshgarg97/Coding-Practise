int height( Node* root);
bool isBalanced(Node *root)
{
    //  Your Code here
    if( root == NULL ) return true;
    int left = height( root->left) ;
    int right = height( root->right) ;
    if( abs(left - right) <=1 && abs(left- right) >=-1 && isBalanced(root->left ) && isBalanced(root->right))
        return true;
    return false;
}
int height( Node* root) {
    if( root == NULL) return 0 ;
    int l = height( root->left) ;
    int r = height( root->right) ;
    return (l> r? l :r) +1;
}