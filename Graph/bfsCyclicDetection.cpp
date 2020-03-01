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
    // Check for undirected graph
    bool isCyclicBFS(T src){

        map <T, bool> visited;
        map <T, T> parent;
        queue <T> q;

        q.push(src);
        visited[src] = true;
        parent[src]  = src;

        while(!q.empty()){

            T node = q.front();
            q.pop();

            // Iterate over the  neighbours of that node leaving parent
            for(auto neighbour: adjList[node]){

                if(visited[neighbour] == true && parent[node] != neighbour){
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = node;
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
    cout<<g.isCyclicBFS(1);
    
    return 0;
}