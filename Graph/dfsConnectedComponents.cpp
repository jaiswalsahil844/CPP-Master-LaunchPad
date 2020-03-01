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
        
        int component = 1;
        dfsHelper(src, visited);
        cout<<endl;

        for(auto i: adjList){

            if(!visited[i.first]){
                dfsHelper(i.first, visited);
                component++;
            }
        }
        cout<<endl<<component<<endl;
    }
};

int main(){

    Graph <string> g;

    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Delhi", "Bhopal");
    g.addEdge("Mumbai", "Bangalore");
    g.addEdge("Agra","Delhi");
    g.addEdge("Andaman","Nicobar");
    
    g.dfs("Amritsar");
    return 0;
}