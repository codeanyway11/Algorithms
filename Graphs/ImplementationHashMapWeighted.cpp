#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;

template<typename T>
class Graph{
    map<T, list< pair <T, int> > > adjList;

public:
    Graph(){
    }

    void addEdge(T u, T v, int wt, bool bidir= true){
        adjList[u].push_back(make_pair(v, wt));
        if(bidir){
            adjList[v].push_back(make_pair(u, wt));
        }
    }

    void printAdjList(){
        for(auto row:adjList){
            T key = row.first;
            cout<<key<<"->";
            for(auto element: row.second){
                cout<< element.first << "(" << element.second <<") ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi", 5);
    g.addEdge("Amritsar", "Jaipur", 8);
    g.addEdge("Delhi", "Siachen", 9);
    g.addEdge("Delhi", "Bangalore", 10);
    g.printAdjList();
    return 0;
}
