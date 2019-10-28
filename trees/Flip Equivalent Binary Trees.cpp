/*
    for future reference
    We can recursively check the following conditions:

    If one of trees is NULL while the other one is not return false
    Otherwise, we know that both trees are NULL or not NULL.
    If both of them are NULL we are fine.
    If none of them are NULL, then we need to make sure
    They have same value
    Recursively calls this function for both of their children.
    We need to make sure whether they have exactly same children  or they will be     same if we flip their children.
    / Two null trees are flip equivalent
        // A non-null and null tree are NOT flip equivalent
        // Two non-null trees with different root values are NOT flip equivalent
        // Two non-null trees are flip equivalent if
        //      The left subtree of tree1 is flip equivalent with the left subtree of tree2 and the right subtree of tree1 is   
        //      flipequivalent with the right subtree of tree2 (no flip case)
        //      OR
        //      The right subtree of tree1 is flip equivalent with the left subtree of tree2 and the left subtree of tree1 is
        //      flipequivalent with the right subtree of tree2 (flip case)
    */
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(( root1 == NULL && root2 !=NULL) ||(root1 !=NULL && root2==NULL))
            return false;
        if( root1 == NULL && root2 ==NULL){
            return true;
        }
        return (root1->val == root2->val)&& ((flipEquiv(root1->left , root2->left) && flipEquiv(root1->right , root2->right )) ||(flipEquiv(root1->left , root2->right ) && flipEquiv(root1->right , root2->left)));   
    }