class Solution {
public:
    //way1:- 
    /*
    bool check(string palindrome){
        for( int i = 0 ,j = palindrome.length()-1 ; i <= j ; i ++, j --) {
            if( palindrome[i] !=palindrome[j] ) 
                return false;
        }
        return true;
    }
    string breakPalindrome(string palindrome) {
        string ans; 
        int n = palindrome.length(); 
        if( n == 1 ) 
            return ans;
        string temp; 
        temp = palindrome;
        //first non 'a' character to a 
        // if all are 'a ' then last character as b
        for( int i = 0 ; i < n;i++ ) {
            if( palindrome[i] !='a'){
                palindrome[i] = 'a';
                if( !check(palindrome) ) // to check if after converting first non a character to 'a' , it still becomes palindrome
                    return palindrome;
                else {
                    palindrome = temp;
                    break;
                }
            }
        }
        for( int i = n-1;i>= 0 ; i -- ){
            if(palindrome[i] !='b'){
                palindrome[i] ='b';
                return palindrome;
            }
        }
        return palindrome;
        
    }
    */
    //way2 :- go upto n / 2  and change the first non a character , if it is
    // if none found , means first half is all 'a' , then second half will also be all 'a' ,, hence complete string is 'aaaaa...', just change last character to 'b'
    string breakPalindrome(string palindrome) {
        string ans; 
        int n = palindrome.length(); 
        if( n == 1 ) 
            return ans;
        for(int i =0 ; i < n/2; i++ ) {
            if( palindrome[i] !='a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};