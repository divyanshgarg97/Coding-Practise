class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.length();
        int suffixsum[n];
        memset(suffixsum, 0 , sizeof(suffixsum));
        suffixsum[n-1] = shifts[n-1] % 26;
        for(int i =n-2; i>= 0 ;i -- ) {
            suffixsum[i] = (suffixsum[i+1] + shifts[i]) % 26; 
        }
        //for( int i= 0 ; i< n ;i++ ) 
        //    cout<< suffixsum[i] << " ";
        for(int i = 0 ; i< n ;i++ ) {
            S[i] = (char)((S[i] - 'a' + suffixsum[i]) % 26 + 'a');
        }
        return S;
    }
};