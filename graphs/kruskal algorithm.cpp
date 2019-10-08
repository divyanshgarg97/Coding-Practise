#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src , dest ,weight;
};
class Disjoint_set{
    unordered_map<int , int > parent;
    public: 
    void makeset(int N ){
        for( int i = 0 ;i< N ;i++) {
            parent[i] = i; 
        }
    }
    int find( int i ) {
        if( parent[i] ==i)
            return i ;
        return find(parent[i]);
    }
    void unions( int x, int y ) {
        int a = find( x) ;
        int b = find( y ) ;
        parent[a] = b;
    }
};

struct compare{ //will sort in descending order
    bool operator()(Edge a , Edge b ){
        if( a.weight > b.weight ) 
            return 1;
        else
            return 0;
    }
};
vector<Edge> KruskalAlgo(vector<Edge > edges , int N ){
    Disjoint_set ds;
    ds.makeset(N) ;
    vector<Edge> ans ;
    while ( ans.size() != N-1){
        Edge temp = edges.back();
        edges.pop_back();
        int src1 = temp.src;
        int dest1 = temp.dest;
        int x = ds.find(src1);
        int y = ds.find ( dest1) ;
        if( x!=y) {
            ans.push_back( {temp.src , temp.dest, temp.weight});//dest1, temp.weight});
            ds.unions(x , y);
        }
    }
    return ans;
}
int main()
{
	vector<Edge> edges =
	{
		{ 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 },
		{ 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 },
		{ 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 }
	};
	sort(edges.begin(), edges.end(), compare()); //sorting in descending order;
	int N = 7;
	vector<Edge> e = KruskalAlgo(edges, N);

	for (Edge &edge: e)
		cout << "(" << edge.src << ", " << edge.dest << ", "
			<< edge.weight << ")" << endl;
	return 0;
}
