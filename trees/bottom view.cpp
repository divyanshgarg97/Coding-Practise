//map< int , int > mp;
//map<int , int > iterator:: itr;
void inorder( Node * root, map<int, int > &mp ,int val ){
    if( root == NULL ) return ;
    
    //mp[val] = root->data ;
    //if(root -)
    inorder( root->left , mp, val - 1);
    mp[val] = root->data;
    inorder( root ->right ,mp, val+1);
}
void bottomView(Node *root)
{
   if( root == NULL ) return ;
   map<int, int> mp;
   inorder( root ,mp, 0 );
   //map <int, int> mp;
   for( auto itr = mp.begin()  ;itr!= mp.end() ;itr++){
       //cout<<itr->first<<" "<<itr->second<<" ";
       cout<<itr->second<<" ";
       
   }
}
