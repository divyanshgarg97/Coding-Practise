//longest substring of distinct characters k in it
#include<bits/stdc++.h>
using namespace std;
void longestsubstr( string s , int n ,int k) {
    int ansb= 0, anse = 0 ;
    int low = 0, high = 0;
    int hash[128]={ 0 };
    //memset( hash, 0 , sizeof(hash));
    unordered_set<char> exist;
    for(; high < n ; high++) {
        exist.insert(s[high]);
        hash[s[high] - 'a']++;
        while( exist.size() > k ) {
            //delete first char of window 
            hash[s[low] - 'a']--;
            if(hash[s[low] -'a'] ==0 )
                exist.erase(s[low]);
            low++;    
        }
        if( high - low > anse - ansb) {
            anse = high; 
            ansb = low;
        }
    }
    cout<< s.substr(ansb , anse - ansb + 1) ;
}
int main() {
    string s; 
    cin >> s;
    int n = s.length();
    int k ;
    cin>> k ;
    longestsubstr(s,n,k ) ;
    return 0 ;
}