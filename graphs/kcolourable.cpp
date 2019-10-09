#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src, dest ;
};
class Graph{
    public: 
    vector<vector<int> > adjlist;
    Graph(vector<Edge> edges , int N ) {
        adjlist.resize(N);
        for( auto i : edges) {
            adjlist[i.src].push_back( i.dest) ;
            adjlist[i.dest].push_back(i.src);
        }
    }
};
vector<char > colorglobal={'y', 'b', 'g', 'r', 'o' , 'w', 'p'};
bool safe( vector<vector<int> > adjlist, int vertex, int colorcheck, vector<int> &colorassigned){
    for( auto i : adjlist[vertex]){
        if( colorassigned[i] == colorcheck)
            return false;
    }
    return true;
}
void kcolorbacktracking(Graph graph, int vertex ,int k , int N , vector<int> &colorassigned,int &possible){
    if( vertex == N){
        //all filled
        cout<< "\n";
        possible++;
        for(int i =0 ;i < N;i++ ){
            cout<< i << " assigned to "<< colorglobal[colorassigned[i]]<<", ";
        }
        return ;
    }
    for( int i = 0 ;i< k ;i++ ){
        if( safe (graph.adjlist, vertex , i , colorassigned)){
            colorassigned[vertex] = i ; 
            kcolorbacktracking(graph, vertex + 1 ,k,  N ,colorassigned,possible );
            colorassigned[vertex]=-1;//backtrack
        }
    }
}
int main(){
    vector<Edge> edges = {
		{0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
	};
	int N = 6;
	Graph g(edges, N);
	int k =3;
	vector<int> colorassigned(N, -1);
    int possible=0;
	kcolorbacktracking(g,0,k,  N , colorassigned,possible);
	cout<< "\n";
	cout<< "total possilbe are "<< possible;

	return 0;
}