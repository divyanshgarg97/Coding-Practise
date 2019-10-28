//654. Maximum Binary Tree

class Solution {
public:
    int getmaxindex(vector<int> &nums, int s , int e ) {
        int max = s; 
        for( int i = s; i < e ;i++ ) {
            if( nums[i] > nums[max])
                max = i ;
        }
        return max;
    }
    TreeNode * go( vector<int> &nums , int s , int e) {
        if( s== e ) 
            return NULL;
        int k = getmaxindex(nums , s, e ) ; 
        TreeNode * root =new TreeNode( nums[k]);
        //flag = 1;
        root ->left = go( nums , s, k) ; 
        root->right = go( nums , k + 1 , e) ;
        return root; 
    }
    
    //preorder to solve the question
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) 
            return NULL ;
        return go(nums ,0 , nums.size()) ; 
    }
};