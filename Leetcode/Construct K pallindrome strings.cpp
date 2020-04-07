class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if( n < k ) 
            return false;
        //for every count we need one string to handle it and it will be in centre
        map<char,int> mp;
        for( int i = 0 ; i< n;i++ ) 
            mp[s[i]]++;
        int count = 0 ; 
        for(auto i : mp){
            if( i.second % 2 == 1) 
                count ++;
        }
        if(count > k ) 
            return false;
        return true;
        
    }
};