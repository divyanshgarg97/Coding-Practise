class Solution {
public:
    /**
     * @param nums: a continuous stream of numbers
     * @param number: a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> &nums, int number) {
        //make a unordered_set to check for previous existence and linked list like data structure something to store linearity of DS and make use of pointers to move around in it , better use unordered_map and vector for convinience
        int n = nums.size();
        if( n==0) return -1;
        unordered_map<int,int> ump;
        vector<int> store;
        int i= 0; 
        while( i < n && nums[i] != number){
            if(ump[nums[i]] == 0)
                store.push_back(nums[i]);
            ump[nums[i]] ++ ;
            i++;
        }
        if( nums[i] == number){
            if( ump[nums[i]] == 0)
                store.push_back(nums[i]);
            ump[nums[i]]++;
            for(int i = 0 ; i < store.size();i++ ){
                if( ump[store[i]]==1) 
                return store[i];
            }
        }
        return -1;
    }
};

//understood and coded from https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
#include<bits/stdc++.h> 
using namespace std; 
struct node{
    char c; 
    struct node * next,* prev;
};
struct node * newnode(char x){
    struct node * newnode = new node; 
    newnode->c = x; 
    newnode->next = newnode->prev = NULL;
    return newnode;
}
void toAddNewNode(struct node ** head, struct node ** tail,char x){//** as we don't want to return updated values of head and tail, using ** ,they will be updated manually
    //https://stackoverflow.com/a/7271680
    struct node * newnode1 = newnode(x);
    if( *head == NULL) { //first node is inserted in DoublyLinkedList
        *head = newnode1;
        *tail = newnode1;
        return;
        // return head; // no need , already made changes in original values only as ** used ,pointer to pointer
    }
    // we need to add at tail
    (*tail)->next = newnode1; 
    (*tail)->next->prev = (*tail);
    (*tail) = (*tail)->next;
    // return head; // no need, already made changes in original values only
}
void deleteNode( struct node ** head, struct node ** tail, struct node * temp){
    if(*head == NULL)
        return; // already DLL is NULL nothing can be deleted in DLL
    if( *head == temp) // first element //adjust head
        *head = (*head)->next; 
    if( *tail == temp) // last element //adjust tail
        *tail = (*tail)->prev; 
    // temp somewhere in between in DLL
    if( temp->next != NULL)
        temp->next->prev = temp->prev;
    if( temp->prev !=NULL)
        temp->prev->next = temp->next;
    delete(temp);
}
void firstNonRepeating(string s) {
    struct node * head = NULL;
    struct node * tail = NULL;
    bool totrackcount[256]; // if count > 1 then true else if not seen or seen once only false;
    struct node * dll[256];
    for( int i = 0 ; i < 256; i++ ){
        dll[i] = NULL; 
        totrackcount[i] = false;
    }
    for( int i = 0 ; i < s.length(); i++ ){
        char c = s[i];
        cout<< "Reading '" << c << "' from stream -> ";
        if( totrackcount[c] == false){ // means never existed or only once
            if(dll[c]== NULL){
                toAddNewNode(&head, &tail, c);
                dll[c] = tail;
            }
            else{
                deleteNode(&head,&tail,dll[c]);
                dll[c] = NULL; 
                totrackcount[c] = true;
            }
        }
        if(head!=NULL) 
            cout<< "first unique is " << head->c << "\n";
    }
}
int main() { 
    string s = "geeksforgeeksandgeeksquizfor";
    firstNonRepeating(s); 
    return 0;  
} 