bool isleaf(Node* root) {
    if( root == NULL) 
        return false;
    else if( root->left ==NULL && root->right ==NULL ) {
        return true;
    }
    return false;
}
void inorder( Node * root , int k ,vector<int> &v , unordered_set<int> &s,int &count ){
    if( root == NULL ) {
        return ;
    }
    v.push_back(root->key);
    inorder(root ->left, k , v, s , count) ; 
    if( isleaf(root) ) {
        if( (s.find(v[v.size() - k - 1]) == s.end()) && v.size() > k ){
            count++ ;
            s.insert(v[v.size() - k - 1]);
        }
    }
    inorder(root->right, k , v , s , count) ;
    v.pop_back();
} 
int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here. 
	vector<int> v; 
	unordered_set<int> s;
	int ans = 0 ; 
	inorder(root , k , v,s,ans); // )
	return ans ;
}