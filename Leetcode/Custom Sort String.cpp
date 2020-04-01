class Solution {
public:
    /*
    string customSortString(string S, string T) {
        map<char,int> mpS; //assigning priority
        int k=1;
        for(auto i : S ) {
            mpS[i] = k ; 
            k++;
        }
        // store frequency of characters of T
        map<char,int> mpTF; 
        for( auto i : T)
            mpTF[i]++ ; 
        // store priority from mpS map
        map<char,int> mpTP;
        for( auto i : T){
            if( mpS[i] ==0)
                mpTP[i] = k++; //as map cannot store values with same key ,hence k++;
            else
                mpTP[i] = mpS[i];
        }
        string ans;
        // reverse the mpTP to get sorted in the order of priority
        map<int,char> mpTFR; 
        for(auto i : mpTP)
            mpTFR[i.second] = i.first;
        
        for( auto i : mpTFR){
            if(mpTF[i.second] != 0){
                for( int j = 0 ;j < mpTF[i.second]; j ++ ) {
                    ans = ans + i.second;
                }    
            }
        }
        return ans;
    }
    */
    string customSortString(string S, string T) {
        //we want sorting with respect to S , so all the elements in S , if they exist in T should come in same order in answer
        map<char,int> mpTF;// to store frequency of char of T //can use arr also,then mpTF[i-'a']++
        for(auto i: T)
            mpTF[i]++;
        string ans;
        for(auto i : S){
            while( mpTF[i] > 0) {
                ans = ans + i;
                mpTF[i]--;
            }
        }
        for( auto i : mpTF){
            if(i.second !=0){
                while(i.second > 0){
                    ans = ans + i.first;
                    i.second--;
                }
            }
        }
        return ans;
    }
    
};