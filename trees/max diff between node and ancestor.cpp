class Solution {
    public:
    int findmin(vector<int> v) {
        int min = v[0];
        for( int i= 1 ;i< v.size() ;i++ ) 
            if( v[i] < min)
                min = v[i];
        return min;
    }
    int findmax(vector<int> v) {
        int max = v[0];
        for( int i = 1 ;i< v.size() ;i++ ){
            if(v[i] > max ) 
                max = v[i];
        }
        return max; 
    }
    bool isleaf(TreeNode* root){
        if( root->left == root->right && root->left == NULL)
            return true;
        return false;
    }
    void path(TreeNode * root , int &finalans, vector<int> &v ){
        if( root == NULL){
            return; 
        }
        v.push_back(root->val);
        if(isleaf(root )){
            int min = findmin(v);
            int max = findmax(v);
            if( finalans < max - min)
                finalans = max - min;
        }
        else{
            path(root ->left , finalans, v) ;
            path(root->right , finalans, v) ; 
        }
        v.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v; 
        int finalans = INT_MIN;
        path(root, finalans , v) ;
        return finalans;
    }