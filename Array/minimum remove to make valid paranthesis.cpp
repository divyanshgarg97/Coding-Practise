class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; 
        int i = 0 ; 
        while( i < s.length() ) {
            if( s[i] == '(')
                st.push(i); 
            else if (s[i] ==')'){
                if(st.size() == 0) {
                    s[i]= '*';
                }
                else
                    st.pop();
            }
            i++;
        }
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        /*
        giving MLE
        string ans; 
        for( int i = 0 ; i < s.length() ;i++){
            if( s[i]=='*')
                continue;
            else
                ans = ans + s[i];
        }*/
        s.erase(remove(s.begin() , s.end() , '*'),s.end());
        //explanation :- remove only removes the * from s and in the extra end spaces just copy the original string there and return an iterator pointing to the location at which remove is done and extra copying happens, hence we can use erase to delete the space
        //eg:-input            d i d i d i d i d i d
        //after remove output:-d d d d d d d i d i d
        //                                |copying of previous begins from here, later removed using erase function
        return s;
        
    }
};