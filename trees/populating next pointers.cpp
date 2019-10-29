//populate next pointers
class Solution {
public:
    //simple bfs
    Node* connect(Node* root) {
        if( root == NULL) {
            return root ;
        }
        queue<Node* > q;
        q.push(root);
        int count = 1;
        q.push(NULL) ; 
        while(count) {
            Node * temp= q.front() ;
            q.pop();
            if(temp){
                count--;
                Node * temp2= q.front() ; 
                temp->next = temp2;
                if( temp->left) {
                    q.push(temp->left) ;
                    count++;
                }
                if( temp->right){ 
                    q.push(temp->right);
                    count++ ; 
                }
            }
            else {
                //NULL found 
                q.push(NULL) ; 
            }
        }
        return root;
    }
};