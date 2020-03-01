#include <iostream>
#include <map>
#include <list>
#include <queue>
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

            // typename list <T> :: iterator it;
            // for(it = i.second.begin(); it != i.second.end(); it++){
            //     cout<<*it<<", ";
            // }
            cout<<endl;
        }
    }

    bool isCyclicHelper(T node, map <T, bool> &visited, T parent){

        visited[node] = true;

        for(auto neighbour: adjList[node]){

            if(!visited[neighbour]){
                bool cycleDetected = isCyclicHelper(neighbour, visited, node);

                if(cycleDetected == true){
                    return true;
                }
            }
            // in this neighbour is already visited
            else if(neighbour != parent){
                return true;
            }
        } 
        return false;
    }
    // Check for undirected graph
    bool isCyclicDFS(){

        map <T, bool> visited;

        // you can for finding cycle in every dfs tree
        for(auto i: adjList){

            T node = i.first;
            if(!visited[node]){
                bool ans = isCyclicHelper(node, visited, node);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
        
    }
};

int main(){


    Graph <int> g;

    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(2,3);

    g.printAdjList();
    cout<<g.isCyclicDFS();
    
    return 0;
}