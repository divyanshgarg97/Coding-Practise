#include<bits/stdc++.h> 
using namespace std; 
//making min segment tree or RMQ with lazy queries
void updateST(int st[],int lazy[], int sl,int sr,int pos, int l , int r, int delta){
    if(sl > sr) return; 
    if( lazy [pos] !=0) {
        st[pos] += lazy[pos]; //update current node value to value which it should be there without lazy
        if(sl!= sr ) { // set descendants to change
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    //no overlap
    if(l > sr || r < sl){
        return;
    }
    //complete overlap i.e.St ranges are small
    if(sl>= l && sr <= r) {
        st[pos] += delta; // update current value or to new value
        if( l != r ) { //set descendants to be changed later as lazy
            lazy[2*pos] += delta;
            lazy[2*pos +1] += delta;
        }
    }
    //partial overlap
    int mid = (sl + sr) / 2; 
    updateST(st,lazy,sl,mid,2*pos,l,r,delta);
    updateST(st,lazy,mid +1, end, 2 * pos + 1, l , r, delta);
    st[pos] = min( st[2*pos] , st[2*pos + 1 ]);
}
int query(int seg[], int lazy[], int sl, int sr, int pos, int ql, int qr){
    if(sl > sr ) return INT_MAX;
    if(lazy[pos] !=0) {
        seg[pos] += lazy[pos];
        if( sl != sr ) { // that is not leaf values of seg tree
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1]+= lazy[pos]; 
        }
        lazy[pos] = 0;
    }
    
    //no overlap
    if(ql > sr || qr < sl)
        return INT_MAX;
    // total overlap i.e query range is greater or equal to segment tree range
    if( sl >= ql && sr <= qr)
        return seg[pos];
    //partial overlap
    int mid = (sl+ sr) >> 1; 
    return min(query(seg,lazy,sl,mid, 2*pos, ql,qr), query(seg,lazy , mid+ 1, 2 * pos + 1, ql , qr)); 
}
int main(){
    
}












