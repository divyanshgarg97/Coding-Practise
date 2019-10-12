int max ( int l , int r ) {
    if( l> r) return l;
    else return r;
}
int height( Node * root ) {
    if( root == NULL) return 0 ;
    int l = height( root -> left);
    int r = height( root -> right);
    return max( l , r ) + 1;
}
int printfirstLOT( Node * root , int i , int flag );
void leftView(Node *root)
{
   if( root == NULL) return ;
   int flag = 0;
   int w = 0;
   for( int i =1; i<= height(root);i++){
       w  = printfirstLOT(root , i , flag);
   }
}
 int printfirstLOT( Node* root , int i , int flag ){
    if( root == NULL) return 0;
    if( flag == 1) {
        return flag ;
    }
    if( i == 1 ){
        cout<<root->data<<" ";
        flag =1;
        return flag ;
    }
    else if ( i > 1){
        int k = printfirstLOT(root ->left  ,i - 1, flag );
        if( k   == 0 ){
            int k  = printfirstLOT( root ->right , i - 1,flag  );
        }
    }
}
