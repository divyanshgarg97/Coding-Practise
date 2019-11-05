#include<bits/stdc++.h>
#define lli long long int
using namespace std;
void take_fast(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ; 
    cout.tie(NULL) ; 
}

void go(){
    lli n ;
    lli f[30+1],g[30+1],h[30+1];// by symmetry g and h are going to be same only
    f[0] = 1;
    f[1] = 0;
    g[0] = 1 ; 
    g[1]= 0;
    for( int i = 2; i<=30;i++ ){
        if( i - 4 >=0)
            g[i-2] = f[i-2] + g[i-4];
        f[i] =f[i-2] + (2 * g[i-2]);// + h[n-2];
    }
    while(1){
        lli n ;
        cin>>n;
        if( n == -1) {
            exit(0);
        }
        else{
            cout<< f[n]<<"\n";    
        }
    }
}
int main() {
    take_fast();
    go(); 
    return 0 ; 
   
}