class Solution {
public:
    /*
    //way1:-
    bool checkValidString(string s) {
        stack<int> left; //store ( indices
        stack<int> star; //store * indices
        for( int i = 0 ;i < s.length(); i++ ) {
            if(s[i] =='(')
                left.push(i);
            else if( s[i] == '*')
                star.push(i);
            else{
                if( left.empty() && star.empty()) //no one can handle current )
                    return false;
                else  {
                    if(!left.empty()) //left top can handle
                        left.pop();
                    else
                        star.pop(); //star can handle
                }
            }           
        }
        //upto the extent we can get stuff from left and star ,get them
        while(!star.empty() && !left.empty()){
            int s = star.top();star.pop();
            int l = left.top();left.pop();
            if( l > s ) //as if like this "*(" then * cannot handle (
                return false;
        }
        if( left.size() == 0 ) //left stack only matters, as * can also be treated as empty
            return true;
        return false;
    }
    */
    //way2 : - backtracking or just recursion,can be converted to 2d dp to store values x = index, y = count,it will eliminate some sub problems
    bool checkValidString(string s){
        return solve(s,0,0);
    }
    bool solve(string s ,int index,int count){
        if( count < 0) 
            return false;
        bool ans = true;
        for( int i = index ; i < s.length() ; i++ ){
            if( s[i]== '(')
                count++;
            if( s[i] == ')'){
                if(count <=0)
                    return false;
                else 
                    count--;
            }
            if( s[i] == '*'){
                return  solve(s, index + 1,count+1) ||solve(s,index + 1, count -1) || solve(s, index + 1, count); 
            }
        }
        return count == 0 ; //imp
    }
};