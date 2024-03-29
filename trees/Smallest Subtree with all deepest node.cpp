class Solution {
public:
    pair<TreeNode *, int > height( TreeNode *root ) {
        if( root == NULL) 
            return {root , 0} ; 
        auto l = height( root->left) ; 
        auto r = height( root->right) ; 
        if( l.second == r.second) 
            return {root, l.second + 1};
        else if( l.second >r.second){
            return {l.first ,l.second + 1};
        }
        else{
            return {r.first , r.second + 1 };
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if( root == NULL) 
            return root; 
        auto ans = height( root); 
        return ans.first;
    }
};