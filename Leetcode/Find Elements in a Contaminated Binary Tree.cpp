/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> us;
    void makeTree(TreeNode * root,int x ){
        if( root== NULL) 
            return;
        root->val = x ; 
        us.insert(x);
        makeTree(root->left, 2*root->val + 1) ; 
        makeTree(root->right, 2 * root->val + 2) ; 
    }
    FindElements(TreeNode* root) {
        //to recover or make tree according to given condition
        makeTree(root,0);
    }
    
    bool find(int target) {
        if(us.find(target) !=us.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */