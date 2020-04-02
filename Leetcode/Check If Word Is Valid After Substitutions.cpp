class Solution {
public:
    bool isValid(string S) {
        //Use stacks, whenever consecutive are 'abc' then remove them,else push, at last stack should be empty for true;
        stack<char> st;
        for( int i = 0 ; i< S.length(); i++ ) {
            if( S[i] == 'a'){
                st.push(S[i]);
            }
            else if( S[i]=='b'){
                st.push(S[i]);
            }
            else{
                if(st.size() < 2) {
                    st.push(S[i]);
                }
                else{
                    char c1 = st.top();st.pop();
                    char c2 = st.top();st.pop();
                    if( c1 == 'b' && c2 == 'a'){
                        continue;
                    }
                    else{
                        st.push(c2);
                        st.push(c1);
                        st.push(S[i]);
                    }
                }
            }
        }
        if( st.size() == 0) 
            return true;
        return false;
    }
};