
class Solution {
public:
    vector<TreeNode * > go(int start , int end) {
        if( start  > end ){ 
            vector<TreeNode * > temp; 
            //TreeNode * newnode = new TreeNode(start);
            temp.push_back(NULL);
            return temp;
        }
        if( end < start){
            vector<TreeNode * > temp; 
            //TreeNode * newnode = new TreeNode(start);
            temp.push_back(NULL);
            return temp;
        }
        if( end == start){
            vector<TreeNode * > temp; 
            TreeNode * newnode = new TreeNode(start);
            temp.push_back(newnode);
            return temp;
        }
        vector<TreeNode * > ans;
        for( int i = start; i<=end;i++ ) {
            vector<TreeNode * > left = go( start ,i - 1); 
            vector<TreeNode * > right = go(i+1 , end ) ; 
            for(auto a : left){
                for( auto b: right){
                    TreeNode * newnode = new TreeNode(i);
                    newnode->left = a; 
                    newnode->right = b;
                    ans.push_back(newnode);
                }
            }
        }
        return ans;  
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode * > ans1; 
        if( n == 0)
            return ans1;
        ans1 = go(1 , n );
        return ans1;
    }