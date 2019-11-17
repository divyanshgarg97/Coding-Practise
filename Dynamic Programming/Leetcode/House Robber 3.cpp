class Solution {
public:
    /*Approach 2:-recursion with memoization(TLE)
    int go(TreeNode * root , unordered_map<TreeNode * ,int > &ump){
        if( root == NULL) 
            return 0 ; 
        if(ump.find(root) != ump.end()){
            return ump[root];
        }
        else{ 
            int i = rob( root->left); 
            int j = rob( root->right) ; 
            int ans1 = i + j; 
            int ans2 = root->val ; 
            if( root->left) 
                ans2 = ans2 + rob(root->left->left); 
            if( root->left)
                ans2 = ans2 + rob(root->left->right);
            if( root->right) 
                ans2 = ans2  +rob(root->right->left); 
            if( root->right) 
                ans2 = ans2 + rob(root->right->right);    
            ump[root] = max(ans1, ans2);
        }
        return ump[root];
    }
    
    int rob(TreeNode* root) {
        Approach1:- Using simple recursion approach(TLE)
        if( root == NULL) 
            return 0 ; 
        //for every node 
        int i = rob( root->left); 
        int j = rob( root->right) ; 
        int ans1 = i + j; 
        int ans2 = root->val ; 
        if( root->left) 
            ans2 = ans2 + rob(root->left->left); 
        if( root->left)
            ans2 = ans2 + rob(root->left->right);
        if( root->right) 
            ans2 = ans2  +rob(root->right->left); 
        if( root->right) 
            ans2 = ans2 + rob(root->right->right); 
        return max(ans1, ans2);
        unordered_map<TreeNode * , int> ump;
        return go( root , ump);*/
    vector<int> go( TreeNode * root) {
        if( root == NULL) {
            vector<int> v(2,0);
            return v ; 
        }
        vector<int> i = go(root->left); 
        vector<int> j = go(root->right); 
        vector<int> v(2,0);
        //dont take
        v[0] =max(i[0],i[1]) + max(j[0],j[1]);
        //take 
        v[1] = root->val + i[0] + j[0];
        return v;
    }
    
    int rob(TreeNode* root) {
        //approach 3 :- for every node return both take and don't take values
        vector<int> a  = go(root); 
        return max(a[0] , a[1]);
    }
    
};
        