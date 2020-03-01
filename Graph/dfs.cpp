#include <iostream>
#include <map>
#include <list>
using namespace std;

template <typename T>
class Graph{

    map <T, list <T> > adjList;

    public:
    Graph(){

    }

    void addEdge(T u, T v, bool bidir = true){

        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){

        // Iterate over the map
        for(auto i: adjList){

            cout<<i.first<<" -> ";
            // i.second is LL
            for(auto entry: i.second){     // T == auto
                cout<<entry<<", ";
            }
            cout<<endl;
        }
    }

    void dfsHelper(T node, map<T, bool> &visited){

        // Whenever to come to a node, mark it visted 
        visited[node] = true;
        cout<<node<<" ";

        // try to find out a node which is neighbour of current node and not yet visted
        for(auto neighbour: adjList[node]){

            if(!visited[neighbour]){
                dfsHelper(neighbour, visited);
            }
        }

    }

    void dfs(T src){

        map<T, bool> visited;

        dfsHelper(src, visited);
    }
};

// Time O(V+E)   // O(V^2) AdjMatrix
// Space O(V)
int main(){

    Graph <int> g;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    
    g.dfs(0);
    return 0;
}