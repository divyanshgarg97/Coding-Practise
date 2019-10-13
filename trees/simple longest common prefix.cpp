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
string  longestcommonprefix( TrieNode* head ,int n ){
    TrieNode * curr = head;
    int flag = 0 ;
    string ans ; 
    while( curr && !(curr->isleaf == 1) && (curr->map.size() == 1)){
        auto i = curr->map.begin() ;
        ans = ans + i->first;
        curr =i->second;
    }
    return ans;
}
int main(){
	string dict[] =
	{
	    "hello","hi","hell"
	};
	TrieNode * head =NULL;
	int n = sizeof(dict)/sizeof(dict[0]);
	for( int i =0 ;i< n ;i++ ) {
	    insert( head , dict[i]);
	}
	cout << "Longest Common Prefix is " << longestcommonprefix(head,n);
	return 0;
}
    	