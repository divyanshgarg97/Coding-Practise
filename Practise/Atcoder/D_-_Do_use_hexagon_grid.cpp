#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp> // added for pbds
// #include<ext/pb_ds/tree_policy.hpp> // added for pbds
#define ll                  long long // 10^19 // 19 digits at max , // int can have 9 digits at max
#define ull                 unsigned long long
#define MOD                 1000000007
// #define INF                 1000000000 // 10^9
#define IOS                 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define mem1(a)             memset(a,-1,sizeof(a))
#define mem0(a)             memset(a,0,sizeof(a))
//Vector Macros
#define all(v)              v.begin(),v.end()
#define unq(v)              v.erase(unique(all(v)),v.end())
#define MIN(c)              *min_element(all(c))
#define MAX(c)              *max_element(all(c))
#define SUM(c)              accumulate(all(c),0)
#define vi                  vector<int>
#define vll                 vector<ll>
#define vii                 vector<pair<int,int>>
#define pb                  push_back
#define ff                  first
#define ss                  second
#define ii                  pair<int,int>
// debug
#define endll               '\n'
#define space               " "
#define printing(v)         cout<< "Printing " << #v; cout<< endll;for(ll i =0;i<v.size();i++) cout<< v[i] << space; cout<< endll;
#define D(x)                cout << #x " = " << (x) << endll
#define D1(x)               cout<< #x " = " << (x) << space
#define INF                 (int)1e9
#define INFLL               (ll)1e18
#define TEST                int t;cin>>t; while(t--)
#define ps(x,y)             fixed<<setprecision(y)<< x; // to set precision to number x upto y decimal digits
#define ffs(a)              __builtin_ffs(a) // find first set
#define clz(a)              __builtin_clz(a) // count leading zeroes
#define ctz(a)              __builtin_ctz(a) // count trailing zeroes
#define popc(a)             __builtin_popcount(a) // count set bits
#define popcll(a)           __builtin_popcountll(a) //count set bits for long long int
#define int                 long long
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
using namespace std;
// using namespace __gnu_pbds;// for pbds
// typedef tree<int,null_type,
// less<int>,rb_tree_tag,
// tree_order_statistics_node_update> pbds;
//------------------------------------------MATH------------------------------//
ll modmul(ll a,ll b,ll mod){return ((a%mod) * (b%mod)) % mod;}
ll modadd(ll a,ll b,ll mod){return((a%mod)+(b%mod)+mod)%mod;}
ll modsub(ll a,ll b,ll mod){return((a%mod) - (b%mod) + mod)%mod;}

//-----------------------------------------CLOCK------------------------------//
// {
//     clock_t t1 = clock();
//     //to check runtime internally of a function
//   	clock_t t0 = clock();
//   	function1();
//  	clock_t t1 = clock();
//   	printf("Runtime = %.10lf s\n\n", (t1 - t0) / (double) CLOCKS_PER_SEC);
// }

//--------------------------------------STRING--------------------------------//
//KMP
// {
// int reset[100000];
// string t,p;
// void kmppreprocess(){
// 	int n = p.length();
// 	reset[0] = -1;
// 	int i = 0 , j = -1;
// 	while(i < n){
// 		while( j >= 0 && p[i] !=p[j])
// 			j = reset[j];
// 		i ++ , j ++ ;
// 		reset[i] = j;
// 	}
// }
// void kmp(){
// 	int n = t.length(), m = p.length();
// 	int i = 0,j = 0 ; 
// 	while(i < n ) {
// 		while( j >=0 && t[i] != p[j])
// 			j = reset[j];
// 		i++,j++;
// 		if(j == m) {
// 			cout<< "found at index" << i - j << "\n";
// 			j = reset[j]; // for next match finding
// 		}
// 	}
// }
// int main(){
// 	IOS
//     cin>>t>>p;
//     clock_t t0 = clock();
//     kmppreprocess();
//     kmp();
// }
// }
//Z-ALGO
//{
// auto z_algo(string str){
//     ll len = str.length();
//     ll l = 0 ; 
//     ll r = 0 ; 
//     vector<ll > z(len);
//     for(ll i = 1; i < len ; i++){
//         if( i > r ) {
//             l = r = i; 
//             while( r < len && str[r] == str[r-l])
//                 r++;
//             z[i] = r - l;
//             r--;
//         }
//         else{
//             ll idx = i - l ;
//             if(i + z[idx] <= r){
//                 z[i] = z[idx];
//             }
//             else{
//                 l = i; // reset the l and search for new window
//                 while( r< len && str[r] == str[r-l])
//                     r ++ ; 
//                 z[i] = r - l ; 
//                 r--;
//             }
//         }
//     }
//     return z;
// }
// int main() {
//     string str,pat; 
//     cin>>str>>pat;
//     string total = pat + '$' + str;
//     auto z = z_algo(total);
//     //     for(ll i = pat.length() + 1 ; i < z.size(); i++ ) {
//     //     if( z[i] == pat.length()) {
//     //         cout<< ( i - pat.length() - 1) << "\n"; // indices where pattern exist in inputstring
//     //     }
//     // }
//     //cout<< "\n Check for z values"; 
//     //cout<< "\n";
//     // for(int i = 0 ; i < z.size(); i++){
//     //     cout<< z[i] <<" ";
//     // }
//     // cout<< "\n";
// }
// }
// MANACHAR
// {
// void manacharAlgo(string s) {
// 	string t = '$' + '#'; 
// 	int n = s.length(); 
// 	FOR(i,n-1)
// 		t = t + s[i] + '#';
// 	t = t + s[n-1] + '@';
// 	int c = 0; // centre of main palindrome
// 	int r = 0 ; // right boundary of main palindrome
// 	int p[t.length()];
// 	memset(p,0,sizeof(p)); 
// 	for( int i = 1; i < t.length() - 1; i ++ ) {
// 		int mirr = 2 * c - i;  //when I consider 'i' as centre and we want where it lie in according to 'c' ( which is main of main palindrome),so that if main palindrome ke andar lie karein toh ,we can use value from it , and later expand if needed

// 		if(i < r)//does i lie within r,i.e. 'i' is greater value than main palindrome ke r se , 
// 			//means 'i' bahar hai main palindrome( so definitely we cannot use it to update value at i) 
// 			p[i] = min(r - i , p[mirr]);
		
// 		// trying to expand by comparing the characters at the centre
// 		while(t[i + (1 + p[i] )] == t[i - (1 + p[i])])
// 			p[i] ++;
// 		if( i + p[i] > r ) {//basically if palindrome centred at 'i' and pallindrome length at 'i' is greater than centre of main palindrome, then we update our main palindrome
// 			// yes then update both c and r 
// 			c = i ; 
// 			r = i + p[i];
// 		}
// 	}
// }
// int main(){
//   IOS
//   string s; 
//   cin>> s; 
//   manacharAlgo(s);
// }
// }
//SUBSEQUENCE ALL
//SUFFIX-ARRAY
//TRIE
//2DKMP


//-----------------------------------------GRAPH-----------------------------------//
//KRUSKAL
// {
// const int maxN = 101;
// //vector<int> adjList[maxN];
// struct edge{
//     int a,b,w;
// };
// edge arr[100000];
// int par[10001];
// bool mycomp(edge a,edge b){
//     if(a.w < b.w) return true;
//     return false;

// }
// int Find(int a){
//     if(par[a]==-1)
//         return a;
//     return par[a] = Find(par[a]);
// }
// void Merge(int a ,int b ){//union function
//     par[a]=b;
// }
// int main(){
//     IOS
//     int sum = 0;
//     int n,m,x,y,w;
//     cin>>n>>m;
//     // initialize parent
//     for(int i =1 ;i<=n;i++) par[i] =-1;
//     for(int i=0;i<m;i++){
//         cin>>arr[i].a>>arr[i].b>>arr[i].w;
//     }
//     sort(arr, arr + m,mycomp);
//     int para= -1;
//     int parb= -1;
//     for(int i =0;i<m;i++){
//         para=Find(arr[i].a);
//         parb=Find(arr[i].b);
//         if(para !=parb){ // were not connected till now , so connect them and add their sum
//             sum +=arr[i].w;
//             Merge(para,parb);// ,y);
//         }
//     }
//     cout<< sum << endl;
// }
// }
//PRIMS
//ARTICULATION POINT(CUT VERTEX/VERTICES)
// {
// const int maxN = 1e5+1;
// vi arr[maxN];
// bool vis[maxN];
// vi inTime,low;
// int timer = 0;
// set<int> articulationPoints; // use set or some bool array for storage as roots can be counted twice at line 43 and 50
// void dfs(int node,int par = -1) {
//     vis[node] = true;
//     low[node] = inTime[node] = timer++;
//     int children = 0;
//     if(int child : arr[node]){
//         if(child == par) continue;
//         if(vis[child]) {
//             // back edge
//             low[node]= min(low[node],inTime[child]); // child can also be ancestor
//         }
//         else{
//             dfs(child,node); // forward edge
//             low[node] = min(low[node],low[child]);
//             if(low[child] >= inTime[node] && par!= -1) { // in bridge we have > only ( we don't check for equality there)
//                 articulationPoints.insert(node);
//                 // cout<< "CUT OFF VERTEX FOUND IS " << node <<endl;
//             }
//             children++; // in else
//         }
//     }
//     if(p == -1 && children > 1)
//         cout<< "CUT OFF VERTEX FOUND IS "<< node << endl, articulationPoints.insert(node);
// }
// int main(){
//     IOS
//     int n,m,x,y;
//     cin>>n>>m;
//     while(m--){
//         cin>>x>>y;
//         arr[x].pb(y),arr[y].pb(x);
//     }
//     int par = -1;
//     for(int i = 1; i<=n;i++){ // as we might have more than one connected components
//         if(!vis[i])
//             dfs(i,par);
//     }
// }
// }
// BRIDGES
// {
// const int maxN = 101;
// vector<int> arr[maxN];
// int inTime[maxN],low[maxN],vis[maxN];
// int timer;
// void dfs(int node,int par){
//     vis[node] = 1;
//     inTime[node] = low[node] = timer;
//     timer++;
//     for(int child:arr[node]){
//         if(child == par) continue;
//         if(vis[child]==1) // back edge found
//             low[node] = min(low[node],inTime[child]);
//         else{
//             dfs(child,node);
//             // if low[child] == inTime[node] means child and node are directly connected means there is a path other than child--- node edge using which the low gets updated for child as inTime[node] , thus not an BRIDGE
//             if(low[child] > inTime[node]) // bridge found
//                 cout << node << "---" << child << space << "is a BRIDGE  " << endl;
//             low[node]=min(low[node],low[child]);
//         }
//     }
// }
// int main(){
//     IOS
//     int n,m,x,y;
//     cin>>n>>m;
//     while(m--)
//         cin>>x>>y,arr[x].pb(y),arr[y].pb(x);

//     dfs(1,-1);
// }
// }
//BIPARTITE
// {
// const int maxN = 1e5 + 2;
// vector<int> arr[maxN];
// bool col[maxN];
// bool vis[maxN];
// bool dfs(int node,bool c) {
//     vis[node]= 1;
//     col[node] = c;
//     for(int child : arr[node]) {
//         if( vis[child]) {
//             if(col[node] == col[child])
//                 return false;
//         }
//         else{
//             if(dfs(child,c^1) == false)
//                 return false;
//         }
//     }
//     return true;
// }
// int main(){
//     IOS
//     cin>>t;
//     memset(col,-1,sizeof(col));
//     dfs(1,0) ;
//     while(t--){
//     }
// }
// }
//DIJIKTRAS/DJIKTRAS
// {
// const int maxN = 1e5 + 2;
// vector<ii> arr[maxN];
// int main(){
//     IOS
//     int n,m,x,y,w;
//     cin>>n>>m;
//     for(int i= 0 ; i< m; i++ ) {
//         cin>> x >> y >> w;
//         arr[x].pb({y,w});
//         arr[y].pb({x,w});
//     }
//     priority_queue<ii,vii,greater<ii> > pq;
//     vector<int> dist(n+1,INF); //
//     int src= 1;
//     pq.push({0,src});
//     dist[src] = 0 ;
//     while(!pq.empty()){
//         int curr = pq.top().second;
//         int curr_d = pq.top().first;
//         pq.pop();
//         for(ii node : arr[curr]){
//             if(curr_d + node.second  < dist[node.first] ) {
//                 dist[node.first] = curr_d + node.second;
//                 pq.push({dist[node.first], node.first});
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//         cout<< dist[i] << space;
// }
// }
//TOPOLOGICAL_SORT KAHN ALGORITHM
// {
// vector<int> arr[100];
// vector<int> res;
// int in[100];
// void kahn(int n){
//     queue<int> q; // to store nodes with In-degree =0
//     for(int i=1;i<=n;i++){
//         if(in[i] ==0)
//             q.push(i);
//     }
//     while(!q.empty()){
//         int cur = q.front();
//         q.pop();
//         res.pb(cur);
//         for(int node : arr[cur]){
//             in[node]--;
//             if(in[node]==0)
//                 q.push(node);
//         }
//     }
//     for(int node:res){
//         cout<< node << space;
//     }
// }
// int main(){
//     IOS
//     int n,m,x,y;
//     cin>>n>>m;
//     for(ll i = 1; i<= m;i++){
//         cin>>x>>y;
//         arr[x].pb(y);
//         in[y]++;
//     }
//     kahn(n);
// }
// }
//UNDIRECTED CYCLE (FIND AND CHECK)
// {
// const int maxN = 1e5+2;
// vector<int> arr[maxN];
// bool vis[maxN];
// bool dfs(int node,int par) {
//     vis[node] =1;
//     for(int child : arr[node]){
//         if(vis[child] == 1) {
//             if(child != par)
//                 return true;
//         }
//         else {
//             if(dfs(child,node) == true)
//                 return true;
//         }
//     }
//     return false;
// }
// }
// DIRECTED CYCLE (FIND AND CHECK)
// {
// const int maxN = 1e6+2;
// vector<int> arr[maxN];
// bool vis[maxN];
// bool dfs(int node , int par) {
//     vis[node] = true;
//     for(int child : arr[node]) {
//         if(vis[child] == true) {
//             if(child!= par)
//                 return true;
//         }
//         else{
//             if(dfs(child,node)== true)
//                 return true;
//         }
//     }
//     vis[node] = false;
//     return false;
// }
// int main(){
//     IOS
//     cin>>t;
//     while(t--){
//     }
// }
// }
// BFS
// DFS
// CONVEX HULL

//---------------------------------------------MATRIX -----------------------------------//
// BFS ON 2D MATRIX
// {
// const int maxN = 1e3 + 2;
// int N , M;
// bool vis[maxN][maxN];
// int dist[maxN][maxN];
// bool isValid(int x,int y){
//     if(x<1 || x > N || y < 1|| y>M)
//         return false;
//     if(vis[x][y]) // already visited
//         return false;
//     return true;
// }

// void bfsGrid(int srcX ,int srcY){
//     queue<ii> q;
//     q.push({srcX,srcY});
//     dist[srcX][srcY]=0;
//     vis[srcX][srcY] = 1;
//     while(!q.empty()){
//         int currX = q.front().ff;
//         int currY = q.front().ss;
//         q.pop();
//         for(int i = 0 ; i < 4;i++){
//             if(isValid(currX + dx[i], currY + dy[i])){
//                 int newX = currX + dx[i];
//                 int newY = currY + dy[i];
//                 dist[newX][newY]= dist[currX][currY]+1;
//                 vis[newX][newY] =1;
//                 q.push({newX,newY});
//             }
//         }
//     }
// }
// }
// DFS ON 2D MATRIX
// {
// const int maxN= 1e3;
// bool vis[maxN][maxN];
// int N,M;// for row and column value
// bool isValid(int x,int y){
//     if(x<1 || x > N || y < 1|| y>M)
//         return false;
//     if(vis[x][y]) // already visited
//         return false;
//     return true;
// }
// void dfs1(int x,int y){ // don't use this in practise , lengthy to write ,use dfs2
//     vis[x][y]=1;
//     // write clockwise(better for remembering)
//     if(isValid(x-1,y)) // up
//         dfs1(x-1,y);
//     if(isValid(x,y+1)) //right
//         dfs1(x,y+1);
//     if(isValid(x+1,y)) // down
//         dfs1(x+1,y);
//     if(isValid(x,y-1)) // left
//         dfs1(x,y-1);
// }
// void dfs2(int x,int y){
//     vis[x][y]=1;
//     cout<< x<< " "<<y<<endl;
//     for(int i=0;i<4;i++){
//         if(isValid(x+dx[i],y+dy[i]))
//             dfs2(x+dx[i],y+dy[i]);
//     }
// }
// int main(){
//     IOS
//     cin>>N>>M;
//     dfs2(1,1);
// }
// }
// PREFIX SUM ON 2D
// DIFFERENCE/DIFERENCE ARRAY ON 2D
// {
// https://discuss.codechef.com/t/cow3e-editorial/64287
// ll a[1001][1001];
// ll b[1001][1001];

// int main()
// {
// 	IOS
// 	ll ans,k;
// 	int n,m,r1,c1,r2,c2,u,q;
// 	cin>>n>>m>>u>>q;
// 	//b will be used as 2d-difference array
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<m;j++)
// 		{
//     		cin>>a[i][j];
//     		b[i][j]=a[i][j];
//     	}
// 	}
// 	// Making of difference array
// 	for(int i=1;i<n;i++){
// 		b[i][0]-=a[i-1][0];
// 	}
// 	for(int i=1;i<m;i++){
// 		b[0][i]-=a[0][i-1];
// 	}
// 	for(int i=1;i<n;i++){
// 		for(int j=1;j<m;j++)
// 			b[i][j]=b[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
// 	}
// 	// Making modifications
// 	while(u--){
// 		cin>>k>>r1>>c1>>r2>>c2;
// 	// Three boundary touching indices must be checked for validity before updation
//     	if(c2+1<m)	b[r1][c2+1]-=k;
//     	if(r2+1<n)	b[r2+1][c1]-=k;
// 		if(r2+1<n&&c2+1<m)
//     		b[r2+1][c2+1]+=k;
//     	b[r1][c1]+=k;
// 	}

// 	//Obtaining Modified Array by performing 2d-prefix array computation on the 2d-difference array
// 	for(int i=1;i<n;i++)
// 		b[i][0]+=b[i-1][0];
// 	for(int i=1;i<m;i++)
// 		b[0][i]+=b[0][i-1];
// 	for(int i=1;i<n;i++) {
// 		for(int j=1;j<m;j++)
// 			b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
// 	}
// 	//Making 2d prefix array for answering queries
// 	for(int i=1;i<m;i++)
// 		b[0][i]+=b[0][i-1];
// 	for(int i=1;i<n;i++)
// 		b[i][0]+=b[i-1][0];
// 	for(int i=1;i<n;i++) {
// 		for(int j=1;j<m;j++)
// 			b[i][j]+=(b[i-1][j]+b[i][j-1]-b[i-1][j-1]);
// 	}
// 	//Answering Queries
// 	while(q--){	
// 		int r1,c1,r2,c2;
// 		cin>>r1>>c1>>r2>>c2;
//      	ans=b[r2][c2];
//     	if(r1-1>=0)
// 			ans-=b[r1-1][c2];

//     	if(c1-1>=0)
//     		ans-=b[r2][c1-1];

// 		if(r1-1>=0&&c1-1>=0)
// 			ans+=b[r1-1][c1-1];
// 		cout<<ans<<"\n";
// 	}
//  	return 0;
//  }
// }

//----------------------------------------------TREE---------------------------------//
// BINARY LIFTING(logN), LCA 
// {
// #define MAX 1001 // let 1000 nodes in the tree
// vector<int> ar[1001]; // adjacency list> ;
// int level[1001];
// const int maxN= 10;
// int lca[1001][maxN+1];
// void dfs(int node,int lvl ,int par){
//     level[node] = lvl;
//     lca[node][0] = par;
//     for(int child : ar[node]){
//         if( child!=par){
//             dfs(child ,lvl + 1, node);
//         }
//     }
// }
// void init(int n ) {
//     dfs(1,0,-1);
//     for(int i= 1; i <= maxN;i++){
//         for(int j = 1; j <= n ;j ++ ) {
//             if(lca[j][i-1] !=-1){
//                 int par = lca[j][i-1];
//                 lca[j][i] = lca[par][i-1];
//             }
//         }
//     }
// }
// // to find the distance between 2 nodes in a tree using LCA in Log(n);
// //dist = level[a] + level[b] - 2* level[LCA] // simple , can easily observe this
// int getLCA(int a ,int b ) { // get the LCA of 2 nodes a,b in tree
//     if(level[b] < level[a] ) swap(a,b); // as we want b to be deeper
    
//     int d = level[b] - level[a];
//     while(d > 0) {
//         int i = log2(d);
//         b = lca[b][i];
//         d -= 1 << i;
//     }
//     if (a ==b ) return a;
//     for(int i = maxN; i >=0  ; i--) {
//         if(lca[a][i] !=-1  && ( lca[a][i]!=lca[b][i])){
//             a = lca[a][i],b=lca[b][i];
//         }
//     }
//     return lca[a][0];
// }
// int getDist(int a ,int b){ // Distance between 2 nodes of a tree
//     int lca = getLCA(a ,b);
//     return level[a] + level[b] - 2 * level[lca];
// }
// int main(){
//     IOS
//     int n,a,b,q; 
//     cin>> n ; 
//     for(int i = 1; i <= n;i++ ) {
//         for(int j = 0 ; j <= maxN; j++ ) {
//             lca[i][j] =-1;
//         }
//     }
//     for( int i = 1; i < n ; i++ ) { //for n nodes there will be n - 1 edges as we are working on trees
//         cin>> a >> b , ar[a].push_back(b),ar[b].push_back(a);        
//     }
//     init(n); // initialize lca array
//     cin>>q;
//     while(q--){
//         cin>> a >> b; 
//         cout<< getDist(a,b) << "\n";
//     }
// }
// }
// FLATTEN A TREE
// {
// int timer; 
// int S[100];//starting time
// int T[100]; // terminating time
// int FT[200];//flattened tree storage
// //basically we will store in S and T with index = node and in FT , we will store with index = time and store which node was there for this time

// //way to implement dfs when we don't want to keep a visited array, is give parent also
// vector<int> ar[100]; // adjacency list representation of graph
// void dfs(int node, int par) {
// 	S[node] = timer;//the time we entered this node, store it
// 	FT[timer] = node; //at time ,timer , which node was we working with
// 	timer ++;//increase timer
// 	for(int child : ar[node]) // to avoid child to go to its parent as parent.
// 		if( child != par)
// 			dfs(child,node);
// 	T[node] = timer;
// 	FT[timer]= node;
// 	timer++;
// }
// using namespace std; 
// int main(){
//     IOS
//     int n,a,b;
//     cin>>n;
//     for(int i = 1; i < n ;i++ ) {
//     	cin>> a>> b; 
//     	ar[a].push_back(b);
//     	ar[b].push_back(a);
//     }
//     timer = 1; 
//     dfs(1,-1);
// }
// }
// HEAVY LIGHT DECOMPOSITION
// SEGMENT TREE
// SEGMENT TREE LAZY
// {
// //making min segment tree or RMQ with lazy queries
// void updateST(int st[],int lazy[], int sl,int sr,int pos, int l , int r, int delta){
//     if(sl > sr) return; 
//     if( lazy [pos] !=0) {
//         st[pos] += lazy[pos]; //update current node value to value which it should be there without lazy
//         if(sl!= sr ) { // set descendants to change
//             lazy[2*pos] += lazy[pos];
//             lazy[2*pos+1] += lazy[pos];
//         }
//         lazy[pos] = 0;
//     }
//     //no overlap
//     if(l > sr || r < sl){
//         return;
//     }
//     //complete overlap i.e.St ranges are small
//     if(sl>= l && sr <= r) {
//         st[pos] += delta; // update current value or to new value
//         if( l != r ) { //set descendants to be changed later as lazy
//             lazy[2*pos] += delta;
//             lazy[2*pos +1] += delta;
//         }
//     }
//     //partial overlap
//     int mid = (sl + sr) / 2; 
//     updateST(st,lazy,sl,mid,2*pos,l,r,delta);
//     updateST(st,lazy,mid +1, end, 2 * pos + 1, l , r, delta);
//     st[pos] = min( st[2*pos] , st[2*pos + 1 ]);
// }
// int query(int seg[], int lazy[], int sl, int sr, int pos, int ql, int qr){
//     if(sl > sr ) return INT_MAX;
//     if(lazy[pos] !=0) {
//         seg[pos] += lazy[pos];
//         if( sl != sr ) { // that is not leaf values of seg tree
//             lazy[2*pos] += lazy[pos];
//             lazy[2*pos+1]+= lazy[pos]; 
//         }
//         lazy[pos] = 0;
//     }
    
//     //no overlap
//     if(ql > sr || qr < sl)
//         return INT_MAX;
//     // total overlap i.e query range is greater or equal to segment tree range
//     if( sl >= ql && sr <= qr)
//         return seg[pos];
//     //partial overlap
//     int mid = (sl+ sr) >> 1; 
//     return min(query(seg,lazy,sl,mid, 2*pos, ql,qr), query(seg,lazy , mid+ 1, 2 * pos + 1, ql , qr)); 
// }
// }
// FENWICK TREE
// {
// const int maxN = 101;
// int fen[maxN];
// int n;
// void update(int i,int add){
//     while(i < n) {
//         fen[i]+=add;
//         i+=(i&(-i));
//     }
// }
// int sum(int i){
//     int s=0;
//     while(i>0){
//         s+=fen[i];
//         i-=(i&(-i));
//     }
//     return s;
// }
// int Find(int k){
//     //binary lifting on fenwick tree
//     int curr = 0,ans =0,prevsum=0;
//     //curr is lower index
//     for(int i = log2(n);i>=0;i--){
//         if(fen[curr+(1<<i)]+prevsum< k){
//             curr = curr + (1<<i);
//             prevsum += ft[curr];
//         }
//     }
//     return (curr+1); // will find me lower_bound for particular prefix value
//     // eg:- I want to find lower_bound for prefix value = 10
//     // basically I want to find the minimum index at which prefix sum becomes >=10
// }
// }
// MERGE SORT TREE
// {
// const int maxN = 1e5+2;
// int arr[maxN];
// vector<int> st[4*maxN];
// void build(int si,int ss,int se){
//     if(ss==se) {
//         st[si].pb(arr[ss]);
//         return;
//     }
//     int mid = (ss+se)>>1;
//     build(si<<1,ss,mid);
//     build(si<<1|1,mid+1,se);
//     int i = 0 ;
//     int j = 0 ;
//     while(i<st[si<<1].size() && j<st[si<<1|1].size()){
//         if(st[si<<1][i] <= st[si<<1|1][j])
//             st[si].pb(st[si<<1][i]) , i++;
//         else
//             st[si].pb(st[si<<1|1][j]) , j++;
//     }
//     while(i<st[si<<1].size())
//         st[si].pb(st[si<<1][i]) , i++;

//     while(j < st[si<<1|1].size())
//         st[si].pb(st[si<<1|1][j]), j++;
// }
// int query(int si,int ss ,int se,int qs ,int qe,int k){
//     if( ss > qe || se < qs)
//         return 0;
//     if( ss>= qs && se <=qe) {
//         int res = lower_bound(st[si].begin(),st[si].end(),k) - st[si].begin(); // first index which is greater than value k-1
//         // for eg :- array values:  2 4 5 7 9
//         //           array index:-  0 1 2 3 4  and k = 5 , Lower bound will return index = 2 , which is required number of elements less than 5
//         //                                     and k = 3, lower bound will return index = 1, which is required number of elements less than 3

//         return res;
//     }
//     int mid = (ss+se)>>1;
//     int l = query(si<<1,ss,mid,qs,qe,k);
//     int r = query(si<<1|1,mid+1,se,qs,qe,k);
//     return (l+r);
// }
// int main(){
//     IOS
//     int n,q,l,r,k;
//     cin>> n>> q;
//     for(int i= 1 ;i <=n;i++ )
//         cin>> arr[i];
//     build(1,1,n);
//     while(q--) {
//         cin>> l>> r>>k;
//         cout<< query(1,1,n,l,r,k)<<endl;
//     }
// }
// }
// BINARY LIFTING ON FENWICK

//------------------------------------------DP--------------------------------------//
// DP ON TREES
// DP WITH BITMASKING
// TREE ROOTING

//--------------------------------------BINARY SEARCH-----------------------------//
// BINARY SEARCH WITH INDEX
// {
// int binary_search_index(vector<int> a,int find) {
//     int n = a.size(); 
//     int l = 0 ; 
//     int r = n - 1; 
//     while( l <= r ) {
//         int mid= r +(l-r ) / 2; 
//         if( a[mid] == find){
//             return mid;
//         }
//         else if(a[mid] < find){
//             l = mid + 1; 
//         }
//         else 
//              r = mid - 1; 
//     }
//     return l; 
// }
// // IN THE MAIN FUNCTION WE CAN CHECK THAT arr[l] == ans or not.
// }

//-------------------------------------------MATH----------------------------------//
// ALL DIVISORS/FACTORS
// {
// void allDivisors(int n){
//     vector<int> v;
//     for(int i = 1; i <= sqrt(n); i++) {
//         if(n%i == 0){
//             if(n/i == i) {
//                 cout<< i << space;
//             }
//             else {
//                 cout<< i<< space;
//                 v.pb(n/i);
//             }
//         }
//     }
//     for(int i= v.size()-1 ; i>=0;i--)
//         cout<< v[i] << space;
// }
// }
// COMBINATORICS/COMBINATION
// {
// lli C(int n , int k ) {
// 	lli ans =1;
// 	if( k > n -k) {
// 		k = n - k ;
// 	}
// 	for(lli i = 1; i<=k;i++){
// 		ans *= (n-i+1);
// 		ans /=i;
// 	}
// 	return ans;
// }
// }
// GCD
// {
// int gcd(int a ,int b ) {
// 	if(b == 0) return a;
// 	return gcd(b,a%b);
// }
// LCM
// //extended gcd add later
// int lcm(int a,int b){
// 	return (a*b) /gcd(a,b);
// }
// }
// LEAST PRIME DIVISOR
// {
// void leastPrime(int n){
//     vector<int> lp(n+1,0);
//     lp[1] = 1;
//     for(int i =2;i<=n;i+=2)
//         lp[i] = 2;
//     for(ll i = 3; i<=n; i++) {
//         if(lp[i] == 0){
//             lp[i] = i;// marking self
//             for(ll j = 2*i;j<=n;j+=i){ // marking all due to me
//                 if(lp[j] ==0)
//                     lp[j] = i;
//             }
//         }
//     }
// }
// void bestLeastPrime(int n){
//     vector<int> lp(n+1,0);
//     lp[1] = 1;
//     for(int i =2;i<=n;i+=2)
//         lp[i] = 2;
//     for(ll i = 3; i<=n; i++) {
//         if(lp[i] == 0){
//             lp[i] = i;// marking self
//             for(ll j = i*i;j<=n;j+=2*i){ // marking all due to me
//                 if(lp[j] ==0)
//                     lp[j] = i;
//             }
//         }
//     }
// }
// }
// MATRIX EXPONENTIATION
// {
// #define N 101
// ll a[N][N];
// ll I[N][N];//Identity matrix
// void mul(ll A[][N],ll B[][N],ll dim){
// 	ll res[dim+1][dim+1];// to save results
// 	for(ll i = 1; i<= dim;i++){
// 		for(ll j = 1; j<= dim;j++){
// 			res[i][j] = 0 ; 
// 			for(ll k = 1; k<= dim;k++){
// 				res[i][j] = (res [i][j] +  (A[i][k] * B[k][j] % MOD)) % MOD;
// 			}	
// 		}
// 	}
// 	for(ll i=1; i<=dim;i++){for(ll j=1;j<=dim;j++){ A[i][j] = res[i][j];}}
// }
// void powerNaive(ll A[][N], ll dim , ll n ){//whenever we pass 2d matrix, we also need to give column
// 	for(ll i = 1; i <= dim; i++ ) {//initializing of identity matrix
// 		for(ll j = 1; j<=dim; j++){
// 			if( i == j ) I[i][j] = 1 ;
// 			else I[i][j] = 0;
// 		}
// 	}
// 	for(ll i = 1; i <=n ;i++ ) {
// 		mul(I,A,dim);//basically perform I = A * I , like res = res * x for finding x ^ n
// 	}
// 	for(ll i = 1; i<= dim;i++){
// 		for(ll j = 1; j<= dim;j++){
// 			A[i][j] = I[i][j];
// 		}
// 	}
// }
// void powerExponentiation(ll A[][N] ,ll dim,ll n){
// 	for(ll i = 1; i<= dim;i++){
// 		for(ll j = 1; j<= dim;j++){
// 			if(i == j ) I[i][j] =1;
// 			else I[i][j] = 0 ;
// 		}
// 	}
// 	while(n){
// 		if(n % 2){ //odd,upate result
// 			mul(I,A,dim); //res *= number
// 			n--;
// 		}
// 		else {//even,upate A
// 			mul(A,A,dim); // number *= number //basically compute n^2
// 			n/=2;
// 		}
// 	}
// 	for(ll i = 1; i<= dim;i++){ for(ll j = 1; i<= dim;j++){ A[i][j] = I[i][j]; }}
// }
// void prllMat(ll A[][N],ll dim){
// 	for(ll i = 1; i<= dim;i++){
// 		for(ll j = 1; j<= dim;j++){
// 			cout << A[i][j] << " ";
// 		}
// 		cout<<"\n";
// 	}
// }
// int main(){
// 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     ll t,dim,n;//n - power // dim - dimension of dim*dim matrix
//     cin>>t;
//     while(t--){
//     	cin>>dim>>n;
//     	for(ll i = 1; i<= dim;i++){
// 			for(ll j = 1; j<= dim;j++){ 
// 				cin>>a[i][j];
// 			}
// 		}
//     	powerExponentiation(a,dim,n);
//     	prllMat(a,dim);
//     }
// }
// }
// PRIME FACTORS/FACTORIZATION
// {
// bool p[MOD];
// void sieve(){ // complete range sieve
// 	for(int i = 2; i < MOD ; i++ ) // iniitializing all are prime
// 		p[i] = true;
// 	for( int i = 2; i < MOD; i++ ){
// 		if( p[i]){
// 			for(int j = 2 * i ; j < MOD; j+=i)
// 				p[j]=false;
// 		}
// 	}
// 	p[0] = false;//by definition of prime
// 	p[1] = false;//by definition of prime
// }
// void sieven(int n){ //sieve upto n (n included)
// 	for(int i = 2; i <= n ;i++ ) {
// 		p[i] = true;
// 	}
// 	for(int i = 2; i<= n;i++){
// 		if( p[i]){
// 			for( int j = 2 * i ; j <= n;j+=i)
// 				p[j] = false;
// 		}
// 	}
// }
// vector<int> pf; // to store all prime numbers in a vector
// void store() {
// 	for(int i = 2; i < MOD; i++ ) {
// 		if(p[i])
// 			pf.push_back(i);
// 	}
// }
// vector<int> ans; // clear it every time you use it
// void factorize1(int n){
// 	int i = 0 ;
// 	ll f = pf[0];
// 	while( f*f <= n){
// 		if(n % f ==0){
// 			ans.push_back(f);
// 			while(n%f==0)
// 				n/=f;
// 		}
// 		i++;
// 		f = pf[i];
// 	}
// 	if(n!=1) // if n was already a prime number,then it won't be check as above loop upto sqrt(n)
// 		ans.push_back(n);
// }
// void factorize2(int n ) { // using the least prime divisor concept
//     vector<int> lp(n+1,0);
//     lp[1] = 1;
//     for(int i =2;i<=n;i+=2)
//         lp[i] = 2;
//     for(ll i = 3; i<=n; i++) {
//         if(lp[i] == 0){
//             lp[i] = i;// marking self marked
//             for(ll j = 2*i;j<=n;j+=i){ // marking all due to me
//                 if(lp[j] ==0)
//                     lp[j] = i;
//             }
//         }
//     }
//     // above will store for every number from 1 to n what is its least prime divisor in O(nLognLogn)(sieve complexity);
//     // now as I only need to factorize n , do this
//     set<int> factors;
//     while(n > 1) { // O(logN) as maximum case mein everytime gets divided by 2
//         int val = lp[n];
//         factors.insert(lp[n]);
//         n = n / lp[n];
//     }
//     // set factors will contain all the prime factors of number n
//     // rather than using set , we can use map too to store the count of each factor also
// }
// int main(){
//     sieven(40);
//     store();
//     int x ;cin>>x;
//     factorize(x);
//     for(int i= 0 ; i < ans.size();i++)
//     	cout<< ans[i] << " ";
//     cout<< "\n";
//     ans.clear();
// }
// }
// SIEVE/SEIVE
// {
// bool p[MOD];
// void sieve(){ // complete range sieve of MOD
// 	for(int i = 2; i < MOD ; i++ ) // iniitializing all are prime
// 		p[i] = true;
// 	for( int i = 3; i < MOD; i+=2 ){
// 		if( p[i]){
// 			for(int j = 2 * i ; j < MOD; j+=i)
// 				p[j]=false;
// 		}
// 	}
// 	p[0] = false;//by definition of prime
// 	p[1] = false;//by definition of prime
// }
// void sieve(int n){ //sieve upto n (n included)
// 	for(int i = 2; i <= n ;i++ ) {
// 		p[i] = true;
// 	}
// 	for(ll i = 2; i<= n;i++){
// 		if( p[i]){
// 			for( ll j = 2 * i ; j <= n;j+=i)
// 				p[j] = false;
// 		}
// 	}
// }
// void bestsieve(int n){
// 	for(int i = 2; i <=n; i+=2)
// 		p[i] = false;
// 	for(ll i = 3; i<=n; i++ ) {
// 		if(p[i]) {
// 			for(ll j = i*i;j<=n;j+=2*i){
// 				p[j] = false;
// 		}
// 	}
// }
// }
// SIEVE/SEIVE SEGMENTATION
// {
// void segmentedSieve(ll a, ll b ) {
// 	sieve();
// 	bool pp[b-a+1];
// 	memset(pp,true,sizeof(pp));
// 	for(ll i = 2; i*i <=b;i++ ) {
// 		if(p[i]){
// 			for( ll j = a; j <= b ; j++ ) {
// 				if( i== j ) //overlapping
// 					continue;
// 				if(j%i ==0) 
// 					pp[j-a] =false;
// 			}
// 		}
// 	}
// }
// }
//-----------------------------------------DISJOINT SET/DISJOINTSET(dsu)-----------------------------//
// {
// int p[MOD];
// int r[MOD];
// using namespace std; 
// //naive
// int find(int a ){
// 	if(p[a] < 0)
// 		return a;
// 	return find(p[a]);
// }
// void uniona(int a ,int b ) {
// 	a= find(a);
// 	b= find(b);
// 	if( a== b) return;
// 	else p[a] = b; 
// }

// // path compression
// int findpc(int a){
// 	if(p[a] < 0) 
// 		return a;
// 	return p[a] = find(p[a]);
// }

// void unionpc(int a ,int b ) {
// 	a = find(a);
// 	b = find(b);
// 	if( a==b ) return;
// 	else p[a] = b; 
// }

// //unionbyrank with path compression
// void findur(int a){
// 	if( p[a] < 0) return a; 
// 	return p[a] = find(p[a]);
// }
// void mergeur(int a ,int b ) {
// 	a = find(a);
// 	b = find(b);
// 	if(a ==b ) return ;
// 	if( r[a] > r[b])
// 		p[b] = a,r[a]+=r[b];
// 	else
// 		p[a] = b,r[b] += r[a];
// }
// }
int p[1002];
int r[1002];
using namespace std; 
//naive
int find(int a ){
	if(p[a] < 0)
		return a;
	return find(p[a]);
}
void uniona(int a ,int b ) {
	a= find(a);
	b= find(b);
	if( a== b) return;
	else p[a] = b; 
}

// path compression
int findpc(int a){
	if(p[a] < 0) 
		return a;
	return p[a] = find(p[a]);
}

void unionpc(int a ,int b ) {
	a = find(a);
	b = find(b);
	if( a==b ) return;
	else p[a] = b; 
}

//unionbyrank with path compression
void findur(int a){
	if( p[a] < 0) return a; 
	return p[a] = find(p[a]);
}
void mergeur(int a ,int b ) {
	a = find(a);
	b = find(b);
	if(a ==b ) return ;
	if( r[a] > r[b])
		p[b] = a,r[a]+=r[b];
	else
		p[a] = b,r[b] += r[a];
}
int t;
int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
signed main(){
    IOS
    int n;cin>>n;
    int parent[ ]
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++) {
        cin>> x[i] >> y[i];
        x[i] += 1002;
        y[i] += 1002;
    } 


    // lets use dsu
    // handle negative number by adding positive threshold
}
