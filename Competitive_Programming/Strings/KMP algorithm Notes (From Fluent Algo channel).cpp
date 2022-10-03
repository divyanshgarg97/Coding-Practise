//prefix function
pi[i]: length of longest proper prefix which is equal to proper suffix ending at i
proper prefix means substring which starts at 0 and does not include the 'i'th character
and proper suffix means substring which ends at i (ie i is included ) and does not include the first character(ie 0th character)

prefix goes from left to right and suffix goes from left to right also but peeche se , ie whenever I am at index 'i' , 
I dont care about i + 1 , i + 2 , or basically anything which is after i 

s = b a b a b a c b b a

pi= 0 0 1 2 3 4 0 1 1 2
    0 1 2 3 4 5 6 7 8 9 = index

property of pi array :- pi[i+1] <= pi[i] + 1 i.e. our pi value atmost increases by one, although it can directly drop to 0 (decrease kuch bhi ho sakta hai ) but 
increase value 1 se hi hoga maximum
proof : Samaj Ni Aaya

S0 S1 S2 ............ Si-3 Si-2 Si-1 | Si
-  -  -                -     -    -  
So I know value for pi[i-1] which is lets say 3,and using that we want to calculate pi[i] 
So we added one more character Si , as pi[i-1] = 3 then , {S0 S1 S2} = {Si-3 Si-2 Si-1} and now we have added one more character which is Si , 
toh agar S4 = Si hua toh we can just incraease value of pi[i-1] + 1
thus, 
if(S[i] == S[pi[i-1]]) // trying to use previous computed pi[i-1] to check ifs it can be used to calculate pi[i]
	pi[i] = pi[i-1] + 1
//if above 'if' is not satisfied means I need to find for some value in {S0 S1 S2} as S3 is not equal to S[i]
// i.e find the longest suffix = prefix before or less in value then pi[i-1];

eg:- 
			S0 S1 S2 S3 S4 S5................ Si-5 Si-4 Si-3 Si-2 Si-1 | Si
			<--pi[i-1]--->			  <-------pi[i-1]-------->
let pi[i-1] = 4 so {S0 S1 S2 S3 S4} =  {Si-5 Si-4 Si-3 Si-2 Si-1} , now if S5 == Si then pi[i] = pi[i-1] + 1
else if( S5 != Si){
	then we will search for longest prefix = suffix value before pi[i-1],let that be k(basically k is next greatest value which is smaller than l) 

	S0 S1 S2 S3 S4 S5................ Si-5 Si-4 Si-3 Si-2 Si-1 | Si
    	<--k-->					    <------k----->

    if( S[i] == pi[k])
    	pi[i] = pi[k] + 1;
    else if// we will find next best length that can be used
    CONCLUSION:- In a nutshell what we are trying to do is,for every pi value upto i - 1 we are trying to find the longest prefix = longest suffix which can be extended to find value for pi[i]
    	// if not equal than we try to find the next best value which can be used and so one and it will continue until that pi value becomes 0
	
	Now lets see how can we find k,i.e. given a length l , we need to find longest prefix = longest suffix length less than l and greatest among all
   
    S0 S1 S2 S3 S4 S5 ................ Si-5 Si-4 Si-3 Si-2 Si-1 | Si
    <------l----->	               <-----------l---------->
    observe above , l = pi[i-1] = 5 then {S0 S1 S2 S3 S4} = {Si-5 Si-4 Si-3 Si-2 Si-1 } and S5 != Si,
    then to find k(which is next best value) , let k = 3 which is next best value.
    Observe one thing in l = 5 ,As we know {S0 S1 S2 S3 S4} = {Si-5 Si-4 Si-3 Si-2 Si-1} then suffix bhi same hi honge
    i.e.{S1 S2 S3 S4} = {Si-4 Si-3 Si-2 Si-1},{S2 S3 S4} = {Si-3 Si-2 Si-1},{S3 S4} = {Si-2 Si-1} ,{S4} = {Si-1} 
    so to get next k , it is k = pi[l-1] as uss k par suffix toh match ho hi rha hoga Si ke peeche vaale suffix se and agar prefix bhi match ho rha hoga k tak toh vaha pi kaa value uss hi hissaab se hoga 
    So,{S0 S1 S2} = {Si-3 Si-2 Si-1} and then we will compare S[k] and S[i] 
    // thus k = pi[i-1] - 1 OR k = l - 1 

    CODE For Prefix Function:-
    pi[0] = 0 ; 
    for(int i= 1 ; i < n ; i++ ) {
    	l = pi[i-1];//peeche kaa value le liya in the hope ki use kar sake ,if not then using that value we can find best value to check until 'l' reaches 0 which means none found to be used
    	while( l > 0 && s[i] != s[l] ) 
    		l = pi[l-1];
    	if( s[i] == s[l]) // so that if l > 0 ki vajah se loop se bahar aaya ho toh check ho jaaye  		
    		++l;
    	pi[i] = l;

    	Time Complexity :- O(n + n) = O(n) and not O(n^2) although it might seem
    }

//prefix function for KMP 
 pi[0] = 0 ; 
 for(int i = 1; i < n ;i++){
 	l = pi[i-1];
 	while( l > 0 && s[i] != s[l])
 		l = pi[l-1];
 	if(s[i]== s[l])
 		++l;
 	pi[i] = l;
 }
 //Matching algorithm for KMP
s(n) = b a a c a b a c a b a c a b b
p(m) = a c a b a c a

//make new string
string t = p + '#' + s; 
Now , what we will do is, we will find pi value of entire t string and we are done as It will find all occurences of string p in s
HOW? Becase of '#'
Why?As we know pi tells us Longest prefix which is also suffix, so any value or index after '#' will never 
have pi value greater than Length of Pattern p as '#' ki vajah se contradiction aa jayega as '#' ek baar hi exist kar raha hai toh match hi ni karega 

code:-
string s,p;
cin>> s >>p ; 
string t = p+'#'+s;
prefixfunction(t);
for(int i = s.length() ; i < t.length() ; i++ ) {
	if(pi[i] == p.length()){
		cout<< "Occured at " << i - p.length() - 1 ; 
	}
} 
Now, the problem is , above will run in O(n+m) good but in O(n+m) space also ,which we dont want
// we can reduce space complexity to O(m) i.e. O(pattern.length()) and lets see how? 
Lets see how we can do that

add '#' at end of string p(pattern string) and make prefix function for that same to same 

Now observe 
	s(n) = b a a c a b a c a b a c a b b
	p(m) = a c a b a c a
	Adding '#' to p ,it becomes p = a c a b a c a # and we will compute prefix function for p 
	FOR s =  b a a c a b a c a b a c a b b
					   i
		     0 1 2 3 4 5 6 7 8 9 
		     To find pi value at i , i.e. pi[i] we need pi[i-1] , using which we initialise or get our first l 
		     if matched we store at pi[i] ,if not , then we go to l = pi[l-1], as '#' has been added earlier,
		     	so never the value of pi[x] exceed length of pattern p as last mein "#" hai toh vo kabhi match hoga hi ni 
		     	so , l = pi[l-1] will always be less than p.length()  so directly make it

   
CODE(FINAL): 
int prev = 0 ; 
int i = 1;
p = p + '#';
int count = 0; 
kmpcompute(p); 
for(int i = 1; i < s.length(); i++ ){
	l = prev ; 
	while( l > 0 && s[i] != p[l])
		l = pi[l-1];
	if( s[i] == p[l])
		l++; 
	prev = l 
	if( l == p.length() - 1) // -1 as '#' was also added
		++count;
}
cout<< count; // no . of occurences of p in s



 //z algo 
 //Z array making for Z algo(just for revision)
 vector<int> z(n,0);
 for(int i = 1; i < n ;i++){
 	if(i > r ) { //finding new
 		l = r = i; 
 		while( r < n && t[r] == t[r-l])
 			r ++;
 		z[i] = r -l; 
 		r --;
 	}
 	else{
 		//trying if I can use previous
 		int idx = i -l ; 
 		if( z[idx] + i <= r) {
 			z[i] = z[idx];
 		}
 		else{
 			// we don't get anything precomputed 
 			// so make new range
 			l = i;
 			while( r < n && t[r] ==t[r-l])
 				r ++ ; 
 			z[i] = r-l; 
 			r --;
 		}
 	}
 }