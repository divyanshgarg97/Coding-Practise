class Solution {
public:
    int nextGreaterElement(int n) {
        //question is basically to find the next_permutation of given number if possible
        // directly use next_permutation(code yourself)
        /*
        string s = to_string(n);
        next_permutation(s.begin(),s.end());
        if( stoll(s) <=n ||stoll(s) > INT_MAX ) 
            return -1;
        return stoll(s);
        */
        string s = to_string(n);
        int ans = nextpermutation(s);
        return ans;
    }
    int nextpermutation(string s ) {// important
        int n = s.length() ; int i = n - 1; 
        while( i > 0 && s[i] <= s[i-1]){//check is already largest, then not possible and return -1;
            i--;
        }
        if( i == 0 ) 
            return -1;
        // now i is at location where element at s[i-1] < s[i]
        // replace i-1 th item to just next greater value from s[i-1] from i to n -1
        int j = n - 1; 
        while( j > i && s[j] <= s[i-1]) // i to n -1 is a decreasing array,hence, begin from end and find first value greater then s[i-1]
            j--;
        swap(s[i-1], s[j]);
        reverse(s.begin() + i , s.end()); // all values from i to n -1 were in decreasing order and we have swapped value at s[i-1] to greater value, hence to get next_permutation , all elements from i to n -1 should be in increasing order,so reverse
        if(stoll(s) > INT_MAX)
            return -1;
        return stoll(s);
    }
};