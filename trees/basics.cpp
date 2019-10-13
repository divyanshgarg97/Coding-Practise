#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    bool isleaf;
    unordered_map<char , TrieNode * > map;
};
//to get new node
TrieNode * getnewnode(){
    TrieNode * newnode = new TrieNode;
    //TrieNode * newnode = (TrieNode * )malloc( sizeof(struct TrieNode));
    newnode->isleaf = false ;
    return newnode;
}
//insert in trie
void insert( TrieNode* &head , string str ) {
    if( head == NULL) 
        head = getnewnode();//to get first node
    int n = str.length() ;
    TrieNode * curr = head;
    int i = 0; 
    while( i< n ){
        //already char is there
        if( curr ->map.find(str[i]) != curr->map.end())
            curr = curr->map[str[i]];
        
        //already char is not there
        else if( curr->map.find(str[i]) == curr->map.end()){
            curr->map[str[i]] = getnewnode();
            curr = curr ->map[str[i]];
        }
        ++i;
    }
    curr->isleaf = true; 
}

//search in trie
bool search( TrieNode* head , string str ) {
    if( head == NULL) //trei does not exist
        return false;
    TrieNode * curr = head;
    int n = str.length() ;
    int i =0 ;
    while( i < n ) {
        curr = curr->map[str[i]];
        if( curr == NULL )  
            return false;
        ++i;
    }
    return curr->isleaf;
}
int main(){
    TrieNode* head = NULL;
	insert(head, "hello");
	cout << search(head, "hello") << " ";   	
	insert( head, "mynameisdivyansh");
	cout<< search(head , "mynameisdivyansh")<<" ";
	insert(head, "helloworld");
	cout << search(head, "helloworld") << " ";  
	cout << search(head, "helll") << " ";  
	insert(head, "hell");
	cout << search(head, "hell") << " ";		
	insert(head, "h");
	cout << search(head, "h") << endl;  		
}