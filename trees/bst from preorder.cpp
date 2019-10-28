//1008. Construct Binary Search Tree from Preorder Traversal

class Solution {
public:
    int nextgreater(vector<int> &nums , int s , int e ) {
        int maxi = -1 ;
        int maxval = nums[s]; 
        for( int i = s; i<= e; i++ ) {
            if( nums[i] > maxval ){ 
                maxi = i ;
                break;
            }
        }
        return maxi ; 
    }
    TreeNode * go (vector<int> &nums , int s , int e ) {
        if( s== e ){
            TreeNode * root = new TreeNode(nums[s]);
            return root; 
        }
        TreeNode * root = new TreeNode (nums[s]);
        int k = nextgreater(nums , s , e );
        if( k == -1 ){//nothing for right side now
            root ->right = NULL;
            root->left = go(nums , s + 1, e);
        }
        else if( k == s + 1) {//nothing for left side now 
            root ->left = NULL; 
            root->right = go( nums , s + 1 ,e ) ; 
        }
        else {
            root->left = go( nums , s+1 , k-1 ) ;
            root->right = go( nums ,k, e) ;
        }
        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return go(preorder , 0 , preorder.size()-1);
    }
};