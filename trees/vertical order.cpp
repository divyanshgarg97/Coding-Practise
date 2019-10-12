/*
void hashIt( Node* root , int value , map<int , vector<int> > &mp){
    if( root == NULL) return ;
    mp[value].push_back(root->data);
    hashIt( root->left , value-1 , mp);
    //mp[value].push_back(root->data);
    hashIt( root->right , value+1, mp);
    //mp[value].push_back(root ->data);
    
}
void verticalOrder(Node *root)
{
    if( root== NULL ) return;
    int val = 0;
    map<int , vector<int> > mp;
    hashIt( root ,val ,  mp);
    for( auto it = mp.begin() ;it!=mp.end() ;it++){
        vector<int > v;
        v=it->second;
        for( int i =0 ;i< v.size() ;i++){
            cout<<v[i]<<" ";
        }
    }
    //cout<<"\n";
    //Your code here
}*/
void verticalOrder( Node* root ) {
    if( root == NULL ) return;
    map<int , vector<int> > mp;
    queue<pair<Node* , int > > q;
    int val = 0 ;
    q.push(make_pair( root , val));
    int val1=0 , val2 = 0;
    while( !q.empty()){
        Node * temp;
        int value ;
        temp= (q.front()).first;
        value = (q.front()).second;
        q.pop();
        mp[value].push_back(temp->data);
        if( temp->left !=NULL ){
            val1 = value-1;
            q.push(make_pair(temp->left , val1));
        }
        if( temp ->right!= NULL) {
            val2 = value+1;
            q.push(make_pair(temp->right , val2));
        }
    }
    for( auto i = mp.begin() ;i!=mp.end();i++){
        vector<int > v;
        v = i->second;
        for( int j = 0 ;j< v.size();j++){
            cout<<v[j]<<" ";
            
        }
        //cout<<"\n";
    }
}


