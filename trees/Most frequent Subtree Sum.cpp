/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int , int > ump;
    int go( TreeNode * root ) {
        if ( root == NULL) {
            return 0 ;     
        }
        if( !root->left && !root->right) {
            //if( ump.find(root->val) == ump.end() ){//no need of this condition as in map it will add new by itself if does not exist already
            //    ump[root->val]++;
            //}
            //else
                ump[root->val]++;
            return root->val;
        }
        int l = go( root->left); 
        int r = go( root->right) ; 
        int sum = l + r + root->val; 
        //if( ump.find(sum) == ump.end()) 
            ump[sum]++;
        //else 
        //    ump[sum]++;
        return sum; 
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans; 
        if( root==NULL) 
            return ans;
        int temp = go(root);
        int m = 0 ; 
        for(auto i = ump.begin() ; i!=ump.end() ; i++ ) {
            if( i->second > m) {
                m = i->second;
            }
        }
        for( auto i = ump.begin() ; i!=ump.end() ;i++ ) {
            if( i->second ==m) 
                ans.push_back(i->first);
        }
        return ans;
    }
};