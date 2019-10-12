bool CheckBst( Node* root, int min , int max){
    if( root== NULL) return true;
    return (root->data <= max) && root->data >=min && CheckBst( root->left ,min , root->data ) && CheckBst( root->right  ,root->data , max);
    
    
}
bool isBST(Node* root) {
    int min = INT_MIN;
    int max = INT_MAX;
    return CheckBst( root, min , max);
    
    // Your code here
    /*if( root == NULL) return true;
    bool leftcheck = isBST( root->left ) ;
    bool rightcheck = isBST ( root->right) ;
    int left = INT_MIN ;
    int right = INT_MAX;
    if( root ->left ) left = root->left->data;
    if( root ->right ) right = root->right->data;
    if( root->data > right || root->data < left )return false;
    return leftcheck && rightcheck;
    //return root->data<=right && root->data>=left && isBST( root->left) && isBST( root->right);
    
    if( root == NULL) return true;
    vector<int > v;
    inorder( root, v);
    for( int i =1 ;i< v.size() ;i++){
        if( v[i] < v[i-1])
            return false;
    }
    return true;
    
}
void inorder( Node* root, vector<int> &v){
    if( root == NULL) return ;
    inorder( root->left, v) ;
    v.push_back( root->data);
    inorder( root->right , v);
}*/
}