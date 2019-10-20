/*The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a text S consisting of only lowercase characters.
The second line contains a word consisting of only lowercase characters.
Print the count of the occurences of anagrams of the word C in the text S.
Example:
Input:
2
forxxorfxdofr
for
aabaabaa
aaba

Output:
3
4
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool checksame(int * a , int * b ) {
    for( int i =0 ;i< 128 ; i++){
        if( a[i] != b[i])
            return false;
    }
    return true;
}
int anagramsearch( string s , string pat ,int n , int m)  {
    if( n  < m) 
        return 0 ;
    int hashs[128]={0};
    int hashpat[128]={0};
    int high = 0 , low = 0 ;
    for( int i = 0 ; i< m ;i++ ){
        hashpat[pat[i]]++;
        hashs[s[i]] ++ ;
    }
    int answer = 0 ;
    if(checksame(hashpat , hashs) )
        answer++;
    for( high = m ; high < n;high ++ ) {
        hashs[s[high]]++;
        hashs[s[low]]--;
        low++;
        if(checksame(hashs , hashpat))
            answer++;
    }
    return answer;
}
int main() {
    int t; 
    cin>> t;
    while( t -- ) {
	    string s ,pat; 
	    cin>> s>> pat;
	    int i = anagramsearch(s, pat, s.length() , pat.length() ) ;
	    cout<<i<<"\n" ; 
    }
	return 0;
}