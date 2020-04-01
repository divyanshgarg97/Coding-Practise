class Solution {
public:
    int minSteps(string s, string t) {
        int count[26];
        memset(count, 0 , sizeof(count)); 
        for( int i = 0 ; i < s.length() ; i++ ) {
            count[s[i] - 'a'] ++ ;
        }
        int ans = 0 ;
        for( int i = 0 ; i < t.length() ; i++ ) 
            count[t[i]-'a']--;
        for( int i = 0 ; i < 26; i++ ) 
            ans = ans + abs(count[i]);
        return ans/2 ;
    }
};