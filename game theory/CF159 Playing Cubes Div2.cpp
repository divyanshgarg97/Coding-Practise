// Codeforces Round #159 (Div. 2), problem: (B) Playing Cubes
//petya first turn is only wasted, in all the later turns both will keep on taking points but when any one of the color dice is over, vasya cannot win points anymore. Indeed later every turn will give points to petya, since there is only single color dice. NOTE: only first dice is wasted
#include<iostream>
using namespace std; 
int main() {
    int a , b; cin>> a >> b; 
    cout<< max(a, b ) - 1<< " " << min(a,b) << "\n";
    return 0 ; 
}