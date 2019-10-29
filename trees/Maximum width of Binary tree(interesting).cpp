
class Solution {
public:
    int ans = 0 ; 
    unsigned long long max( unsigned long long a ,unsigned long long b){
        return a > b ? a: b;
    }
    unordered_map<unsigned long long ,unsigned long long> ump;
    void dfs( TreeNode *root , unsigned long long  level ,unsigned long long pos){
        if( root == NULL ) 
            return; 
        if(ump.find(level) == ump.end()){
            ump[level] = pos;
        }
        ans = max(ans , pos - ump[level] + 1);
        dfs(root->left , level + 1, 2 * pos + 1);
        dfs(root->right , level + 1, 2 * pos + 2);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs( root , 0 , 0 ) ;
        return ans;
    }
};