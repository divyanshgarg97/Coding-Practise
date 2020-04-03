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
    vector<vector<int> > ans;
    vector<int> anstemp;
    //way1: normal BFS approach
    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        //bfs
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); 
        int size = 1; 
        while(size >=0){ //imp
            TreeNode * temp = q.front();
            size--;
            q.pop();
            if( temp == NULL) {
                q.push(NULL);
                size++;
                ans.push_back(anstemp);
                anstemp.clear();
                if( size == 0) //imp
                    break;
            }
            else{
                anstemp.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                    size++;
                }
                if(temp->right){
                    q.push(temp->right);
                    size++;
                }
            }
        }
        return ans;    
    }
    */
    //recursion
    void recur(TreeNode * root, int depth){
        if(root == NULL) 
            return ;
        if( ans.size() == depth){
            //if depth = 0 then ans[0] vector should exist
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(root->val); //will create problem if not already existed space
        if( root->left)
            recur(root->left,depth+1) ;
        if(root->right)
            recur(root->right,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        recur(root,0);
        return ans;
    }
};