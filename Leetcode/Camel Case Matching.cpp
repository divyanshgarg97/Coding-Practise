class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        /*Way1:-
        //stacks for every string ,move in that string , if character matches that of pattern push in stack else don't push, once all the pattern elements in inside, no more upper case letter should come after that.actually we don't need stack,2 pointers will suffice
        int n = queries.size(); 
        vector<bool> ans;
        for(auto s : queries){ //O(totalqueries * (sum of length of all s)) = O(q * n ) 
            int ptr1 = 0 ; 
            int ptr2 = 0 ; 
            while( ptr2 < pattern.length() && ptr1 < s.length()){ //O(s.length())
                if( pattern[ptr2] == s[ptr1]){
                    ptr1++;
                    ptr2++;
                }
                else if(isupper(s[ptr1])){
                    ans.push_back(false);
                    goto l1;
                }
                else 
                    ptr1++;
            }
            
            if(ptr1 == s.length() && ptr2== pattern.length()){//O(1)
                ans.push_back(true);
                goto l1;
            }
            else if( ptr2 !=pattern.length()){
                ans.push_back(false);
                goto l1;
            }
            else{
                while( ptr1 < s.length()){
                    if(isupper(s[ptr1])){
                        ans.push_back(false);
                        goto l1;
                    }
                    else 
                        ptr1++;
                }
            }
            ans.push_back(true);
            l1:
                cout<<"";
        }
        return ans;
    }
    */
    //Way2:- go through each query ,check all Pattern characters appear in Query string or not in the same order and assign them to something else,after that all the non-matched charcters in Query should be Lowercase
        int n = queries.size(); 
        vector<bool> ans;
        for( auto s : queries){
            bool ok = false;
            int p = -1;
            for( int k = 0; k < pattern.length();k++) {
                p = s.find(pattern[k],p+1); //in pattern // search from index p+1 in s and everytime store found index in p itself as we need to find pattern in s in same order, so p will be changing according to last found position in s , and search from p +1 position next time
                if( p == -1 ) {
                    ans.push_back(false);
                    ok = true;
                    break;
                }
                else{
                    s[p] = 'a';//later will check whether all non-matched should be lowercase, then 'a' wont affect , as itself lowercase
                }
            }
            if(!ok){
                for(int i : s ) {
                    if( isupper(i)){
                        ans.push_back(false);
                        ok = true;
                        break;
                    }
                }
                if(!ok)
                    ans.push_back(true);
            }
        }
        return ans;
    }
    
};