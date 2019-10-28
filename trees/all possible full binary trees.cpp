class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if( N % 2 == 0)
            return {};
        if( N ==1){
            vector<TreeNode * > temp;
            TreeNode * newnode = new TreeNode(0);
            temp.push_back(newnode);
            return temp;
        }
        vector<TreeNode * > ans;
        for( int i = 1; i < N;i += 2) {
            vector<TreeNode* >  left = allPossibleFBT(i ) ;
            vector<TreeNode * > right = allPossibleFBT(N - i - 1);
            for( TreeNode* a : left){
                for(TreeNode * b : right){
                    TreeNode * root = new TreeNode(0);
                    root->left = a; 
                    root->right = b;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};