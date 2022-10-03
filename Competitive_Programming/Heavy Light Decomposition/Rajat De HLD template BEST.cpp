// Submission for question : - https://www.codechef.com/problems/CHEFTREE
// lazy seg tree with bit , update and query
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const long long inf = 1LL << 61;
int t;
int n , q;
int A , B;
int a , b;
int c[N];
vector < int > v[N];
int baap[N];
int depth[N];
int subtree[N];
int head[N];
int cur;
int arr[N];
int start[N];
int bit[N];
long long lazy[SN];
long long segtree[SN];
int type , val;
void dfs(int node , int parent){
    baap[node] = parent;
    subtree[node] = 1;
    for(int x : v[node]){
        if(x != parent){
            depth[x] = depth[node] + 1;
            dfs(x , node);
            subtree[node] += subtree[x];
        }
    }
}
void hld(int node , int parent){
    start[node] = ++cur;
    arr[cur] = c[node];
    int idx = -1;
    for(int x : v[node]){
        if(x != parent){
            if(idx == -1 || subtree[x] > subtree[idx]){
                idx = x;
            }
        }
    }
    if(idx != -1){
        head[idx] = head[node];
        hld(idx , node);
    }
    for(int x : v[node]){
        if(x != parent && x != idx){
            head[x] = x;
            hld(x , node);
        }
    }
}
void update(int idx){
    while(idx <= n){
        ++bit[idx];
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int query(int l , int r){
    return query(r) - query(l - 1);
}
void build(int l , int r , int node){
    lazy[node] = 0;
    if(l == r){
        segtree[node] = 1LL * A * arr[l] + B;
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
    }
}
void push(int l , int r , int node){
    if(lazy[node]){
        segtree[node] += lazy[node];
        if(l != r){
            lazy[node + node] += lazy[node];
            lazy[node + node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int l , int r , int node , int ql , int qr , long long val){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] = val;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr , val);
    update(mid + 1 , r , node + node + 1 , ql , qr , val);
    segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
}
int query(int l , int r , int node){
    push(l , r , node);
    if(segtree[node] < 0){
        return -1;
    }
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    int ret = query(l , mid , node + node);
    if(ret == -1){
        ret = query(mid + 1 , r , node + node + 1);
    }
    return ret;
}
void relax(){
    while(segtree[1] >= 0){
        int x = query(1 , n , 1);
        update(1 , n , 1 , x , x , -inf);
        update(x);
    }
}
void hld_update(int a , int b , long long val){
    while(head[a] != head[b]){
        if(depth[head[a]] > depth[head[b]]){
            swap(a , b);
        }
        update(1 , n , 1 , start[head[b]] , start[b] , val);
        b = baap[head[b]];
    }
    if(depth[a] > depth[b]){
        swap(a , b);
    }
    update(1 , n , 1 , start[a] , start[b] , val);
}
int hld_query(int a , int b){
    int res = 0;
    while(head[a] != head[b]){
        if(depth[head[a]] > depth[head[b]]){
            swap(a , b);
        }
        res += query(start[head[b]] , start[b]);
        b = baap[head[b]];
    }
    if(depth[a] > depth[b]){
        swap(a , b);
    }
    res += query(start[a] , start[b]);
    return res;
}
int main(){
    scanf("%d" , &t);
    while(t--){
        scanf("%d %d" , &n , &q);
        scanf("%d %d" , &A , &B);
        for(int i = 1 ; i <= n ; ++i){
            scanf("%d" , &c[i]);
            v[i].clear();
            bit[i] = 0;
        }
        for(int i = 1 ; i < n ; ++i){
            scanf("%d %d" , &a , &b);
            v[a].emplace_back(b);
            v[b].emplace_back(a);
        }
        depth[1] = 0;
        dfs(1 , 0);
        cur = 0;
        head[1] = 1;
        hld(1 , 0);
        build(1 , n , 1);
        while(q--){
            scanf("%d %d %d" , &type , &a , &b);
            if(type == 1){
                scanf("%d" , &val);
                hld_update(a , b , 1LL * val * A);
            }
            else{
                relax();
                printf("%d\n" , hld_query(a , b));
            }
        }
    }
}
