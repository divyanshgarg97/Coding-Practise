class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n1= s1.length(); 
        int n2 = s2.length(); 
        if( n1 != n2) return -1;
        int x1=0,y1=0,x2=0,y2=0;
        for( int i = 0; i< n1;i++ ) {
            if(s1[i] == s2[i]){ //ignore all similar characters
                continue;
            }
            //count all in x and y which are not same
            if( s1[i] == 'x') x1++;
            if( s2[i] == 'x') x2++;
            if( s1[i] == 'y') y1++;
            if( s2[i] == 'y') y2++;
        }
        if( (x1 + x2) % 2 != 0 || (y1 + y2) % 2 !=0 ) // if odd then not possible to divide in 2 different strings hence, not possible
            return -1;
        // find pairs xx in s1 and yy in s2 can be made equal with one swap
        int ans = 0 ; 
        //x_x in s1 and y_y in s2 where _ can be anything, can be made same with 1 swap
        while(x1 - 2 >=0 && y2 -2 >=0){
                ans ++ ; 
                x1-=2; 
                y2-=2;
        }
        //x_x in s2 and y_y in s1 where _ can be anything, can be made same with 1 swap
        while( x2 -2>= 0 && y1-2 >=0) {
                ans ++ ; 
                x2-=2; 
                y1-=2;
            }
        //only one type will be left , xy and yx , if that is case , 2 swaps needed
        if(x1 == 1 && y1 == 1 && x2 == 1 && y2 == 1 ) 
            ans = ans + 2; 
        return ans;
    }
};