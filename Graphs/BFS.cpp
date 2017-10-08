#include<iostream>
#include<list>
#include<queue>
using namespace std;

//Adj List Implementation for Integer Nodes
class Graph{
    int V;
    list<int> *adjList;
public:
    Graph(int v){
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v, bool bidir=1){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(int i=0; i<V; i++){
            cout<<i<<"->";
            for(int node: adjList[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }

    void BFS( int src, int dest ){
        queue<int> q;
        bool *visited = new bool[V+1]{0};
        int *dist = new int[V+1]{0};
        int *parent = new int[V+1];
        for(int i=0; i<V; i++){
            parent[i] = -1;
        }
        q.push(src);
        visited[src] = 1;
        dist[src] = 0;
        parent[src] = -1;
        while( !q.empty() ){
            int node = q.front();
            q.pop();
            cout<< node <<" ";
            for(int neighbour : adjList[node]){
                if( !visited[neighbour] ){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] =node;
                }
            }
        }
        cout<<endl;
        for(int i=0; i<V; i++){
            cout<< i <<" Node having distance " <<dist[i]<<endl;
        }

        cout<<"Shortest distance is "<<dist[dest]<<endl;
        cout<<"Shortest path is ";
        int temp = dest;
        while( temp!= -1){
            cout<<temp<<" <-- ";
            temp = parent[temp];
        }
    }
};




int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(5, 3);
    g.printAdjList();
    g.BFS(0, 5);
    return 0;
}
