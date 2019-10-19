class Solution {
public:    
    int lengthOfLongestSubstring(string s) {
        int high = 0 , low = 0 ;
        int anse = 0 , ansb = 0 ;
        unordered_set<char> exist;
        for(high= 0 ; high < s.length(); high ++ ) {
            if( exist.find(s[high]) == exist.end()){
                exist.insert(s[high]);
                if( anse - ansb < high + 1 - low ) {
                    anse = high + 1; 
                    ansb = low;
                }
            }
            else{
                // we are looking to make new window now
                while( exist.find(s[high]) != exist.end()){
                    exist.erase(s[low]);
                    low++;
                }
                exist.insert(s[high]);
            }
        }
        return anse - ansb;
    }
};