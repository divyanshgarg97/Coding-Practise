class Solution {
public:
    //LIKE floyd warshall algo of linked lists
    /*
    int getSquareValues(int n){
        int temp, sum = 0 ; 
        while( n > 0 ){
            temp = n % 10 ;
            sum = sum + temp* temp ; 
            n = n / 10 ; 
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n; 
        int fast = n ; 
        do{
            slow = getSquareValues(slow);//one step forward
            fast = getSquareValues(fast);//one step forward
            fast = getSquareValues(fast);// second step forward
            if( fast ==1) return 1;// as if it is going to reach 1 , fast will reach first// hence, little optimization
        }
        while( slow!= fast);
        if( slow == 1 ) 
            return true;
        else 
            return false;
    }
    */
    //using hashing ,i.e. whenever same value come one more time and if not 1 reached yet ,that means it will never reach the 1 now
    bool isHappy(int n){
        unordered_set<int> us;
        us.insert(n);
        if(n == 1 ) 
            return true;
        int temp ;
        while(1){
            int sum = 0; 
            while( n > 0) { //logn for every number n 
                temp = n % 10; 
                sum += temp* temp;
                n/=10;
            }
            n = sum;
            if(sum == 1) 
                return true;
            else if( us.find(sum) !=us.end()) {//means already occured somewhere,hence will loop ,return false
                return false;
            }
            else {
                us.insert(sum);
            }
        }
        return true;
        
    }
};