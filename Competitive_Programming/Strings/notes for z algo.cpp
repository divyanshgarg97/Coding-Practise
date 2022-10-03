[l,r]
z[i] = 3; // means the longest suffix starting from i is of length 3 which is equivalent to prefix
mean at index ith ( or starting at index i) ,there is a suffix(suffix is starting from i) which is also the prefix of the starting
eg : str = "abcafsabcaf";
     z[] =        3  

lets take interval [l,r] which will tell us that [l,r] jitna substring is equivalent to prefix of complete string
i.e itna l se r tak kaa substring already prefix of this total string ke barabar ho chuka hai
eg:-
str = "abcafsabcaf"
             l  
               r  means [l,r] which is abc also exists as prefix of str
basically we want to run this algo in O(n+m) time.
so our motive is lets say we already have some values computed for substring l to r  and somewhere in future ,
one more time we get that same substring , so want to use the values which where already computed for that l,r range


totalstring = pat + $ + text
z[0] = 0 always
take one pointer i which will begin from 1 to total length
Connection between l , r and i :- 
NECESSARY :- Always we need to fullfill that 1 <= l <= i <= r < total.length() , if it is not fulfilled then we will try to make it
how it can exceed ? 
i > r 
then we will make l = i and r = i ;

initialy take l = 0 and r = 0 (both taken same)

if( total[r] == total[r-l]) 
	r ++ ; 
means initialy both l and r were equal , and in some point both total[r] == total[r-l] then we want to increase the range,i.e we want to increase the interval
, to increase the interval , we keep l same and r increase taaki longest substring bann sake


now ,how to fill z values
z[i] = r - l ; // as we are maintaining r and l such that it contains longest prefix which is also suffix for ith index(suffix start from ith index)
but this above thing will have some flaw
lets see what it is,lets see:-
eg :- 				abcabcd 
expected l and r position          l r
but r will be here                    r(r will be 1 value forward because humne jo comparison loop lagaaya tha usme toh humne r++ kar diya tha , toh r 1 value aage hi hoga)

but dhyan se dekho toh fayda bhi hogaya 
see eg: abcabcd
	0123456
	   l  r = r - l = 6 -3 ie 3 toh directly length mil gya
	    and later r -- kar dunga taaki r jo hai vo index 5 par aa jaaye and humara inteval l - r prefix = suffix vaala string contain karein , so effectively
code:-
	l=0,r =0;
	if( total[r] == total[r-l]) // if condition kind of doesn't make sense as r toh aage aur bhi bhadega , toh use while loop 
		r ++ ; 
	z[i] = r - l; 
	r--;

	i.e.
	l = 0 ,r = 0 ; 
	//also check ki kahi r ,total length hi na paar kar jaaye
	while( r < total.length() && total[r] == total[r-l])
		r ++;
	z[i] = r - l;
	r --;

now lets see when i <=r 
i.e. 
else if( i <= r ) {
means now I have the possibility to use previous calculated z value, (possibility only , it is not that we will 100% use it)

basically now if i <= r than means i is lying between l and r i.e l < i <= r
eg: abcdabcdabcd              
             i  
            l r
    as in example , I can see that i is in between l and r , and I know l and r store the longest substring which is prefix and suffix till now, so definitely l se r vaale substring abc kaa values first abc par bhi computed hoga , 
    so why not i jaha hai vaha kaa value nikalne ke liye first occurence of abc ka istemaal kar len
    now,how will we get index of b i.e. 1
    0123456789
    abcdabcdabcd 
    	     i
    	    l r
    now try to find index of first b that is 1 , we are not looking for first a because that will already be matched as l has already matched it 
    // relative index find
    ll index = i - l; // relative indexing
    //basically above indexing or relative indexing i - l  is giving me ki l se kitna aage i hai ,vo hi toh index hoga pehle b kaa,as prefix bhi vo hi hai

    //now check can we use already computed value
    if( z[index] < r - i + 1){ // understand this condition
    	// lets analyse this above condition which can also be written as z[index] + i  < r + 1 OR z[index] + i <= r 
    	basically what we want to check is as we know humesha i <= r and i should never - ever exceed r value
    	so if I add directly z[index] to i than it might happen that it will exceed r which we don't want to do  , as l to r we know suffix equal prefix , but after r , we dont know if suffix = prefix or not
    	conclusion :- if( z[index] + i <=r ) {
    					then z[i] = z[index] ; 
    				}
    				else {
    					l = i;
    					while( r < total.length() and tot[r] == tot[r-l])
    						r ++ ; 
    					z[i] = r -l ;
    					r--;
    				}

    }
    else{
    	l = i; 
    	while( r < total.length() and tot[r] == tot[r-l])
    		r ++;
   		z[i] = r - l ; 
   		r -- ; 
    }



}

for(int i= 1; i < total.length() ; i++){

}