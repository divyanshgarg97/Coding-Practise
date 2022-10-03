#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define pb push_back
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
             tree_order_statistics_node_update> pds;


ll n;
const ll N=463005;
vector <ll> arr(N);
pds mst[N];

void init(ll pp){
    for(ll i=0;i<4*pp;i++)
        mst[i].clear();
}

void build(ll si,ll ss,ll se){
    if(ss==se){
        mst[si].insert({arr[ss],ss});
        return;
    }
    for(ll i=ss;i<=se;i++)
        mst[si].insert({arr[i],i});
    ll mid=(ss+se)/2;
    build(si<<1,ss,mid);
    build(si<<1|1,mid+1,se);
}

ll query(ll si,ll ss,ll se,ll qs,ll qe,ll v,ll idx){
    if(ss>qe or se<qs)  return 0;
    if(ss>=qs and se<=qe){
        ll k=mst[si].order_of_key({v,idx});
        return k;
    }
    ll mid=(ss+se)/2;
    return query(si<<1,ss,mid,qs,qe,v,idx) + query(si<<1|1,mid+1,se,qs,qe,v,idx);
}

void update(ll si,ll ss,ll se,ll index,ll v,ll nw){ // point update at index i with previous value v , and new value to be nw
    if(si<ss or se<si)  return;
    if(ss==index and se==index){
        mst[si].erase(mst[si].find({v,index}));
        mst[si].insert({nw,index});
        return;
    }
    ll mid=(ss+se)/2;
    update(si<<1,ss,mid,index,v,nw);
    update(si<<1|1,mid+1,se,index,v,nw);
    mst[si].erase(mst[si].find({v,index}));
    mst[si].insert({nw,index});
}

int main()
{
    cout<< "HERE";
    ll test,i,j,queries;
    scanf("%lld",&test); // number of test cases
    while(test--){

        scanf("%lld",&n);  //number of elements in the array
        init(n);        // initializing the policy based tree

        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);  //scanning the array
        }

        build(1,1,n);

        cin>>queries;       //number of queries
        while(queries--)
        {
            ll choice;
            scanf("%lld",&choice);      //if choice is 0 -> it represents query, choice 1 -> represents update
            if(choice==0)
            {
                ll l,r,x;
                scanf("%lld %lld %lld",&l,&r,&x);       //  the x-th number in sorted a[l ... r] segment

                ll low = mst[1].find_by_order(0)->first, high = mst[1].find_by_order(n-1)->first , mid, ans ;

                // binary search to find the x-th number

                while(low <= high)
                {
                    mid = low + high >> 1;
                    ll k = query(1,1,n,l,r,mid,1005);       // i have considered the highest element in the array to be 1000, change according to your program
                    if(k >=x )
                    {
                        ans = mid;
                        high = mid-1;
                    }
                    else low = mid+1;
                }

                printf("%lld\n",ans);

            }
            else
            {
                // Update the profit of the idx-th shop to x

                ll idx,x;
                scanf("%lld %lld",&idx,&x);
                update(1,1,n,idx,arr[idx],x);
                arr[idx]=x;
            }

        }

    }
    return 0;

}
