#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int src , dest , weight ;
};
struct node{
    int dest, weight;
};
class Graph {
    public:
    vector<vector<node > > adjlist;
    Graph(vector<Edge > edges, int N ){
        adjlist.resize(N);
        for( auto i : edges){
            int src1 = i.src;
            int dest1 = i.dest;
            int weight1 = i.weight;
            adjlist[src1].push_back({dest1, weight1});
        }
    }
};
struct compare{
    bool operator() (node a , node b) { // the top will be minimum, making minheap
        if ( a.weight > b.weight)
            return 1;
        return 0;
    }
};
void printmindistance(int source, vector<int> &distanceyet, int N) {
    for( int i = 0 ;i< N ;i++ )
        cout<< "Source As " << source<< " to Destination "<< i << " in minimum distance "<<distanceyet[i]<<"\n";
}
void djiktrasalgo(Graph &graph, int src , int N){
    priority_queue<node, vector<node>, compare> pq;//to get always minimum path edge from particular vertex
    vector<vector<node> > adj = graph.adjlist;
    vector<int> distanceyet(N, INT_MAX);
    distanceyet[src] = 0;
    pq.push({src , 0});
    vector<bool > done ( N , false);
    done[src] = true;
    vector<int> ancestor(N , -1);
    while( !pq.empty()){
        auto mindistance = pq.top();
        pq.pop();
        cout<<"poped vertex is "<< mindistance.dest<<"\n";
        int vertex = mindistance.dest;
        //done[vertex]= true;
        for( auto i : adj[vertex]){
            if(!done[i.dest]){
                int dist = i.weight;
                int vertexat = i.dest;
                if( distanceyet[vertex] + dist< distanceyet[vertexat]){
                    distanceyet[vertexat] = distanceyet[vertex] +dist ;
                    pq.push({vertexat , distanceyet[vertexat]});//relaxed and put in priority_queue
                    cout<< "pushed in pq"<<vertexat<<"\n";
                }
            }
        }
        done[vertex] = true;//relaxed all of its neighbour and now its work is done
        
    }
    printmindistance(src, distanceyet, N);
}
int main()
{
	vector<Edge> edges =
	{
		{0, 1, 10}, {0, 4, 3}, {1, 2, 2}, {1, 4, 4}, {2, 3, 9},
		{3, 2, 7}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}
	};
	int N = 5;
	Graph graph(edges, N);
	djiktrasalgo(graph, 0, N);
	return 0;
}