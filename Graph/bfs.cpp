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

            cout<<endl;
        }
    }

    void bfs(T src){

        queue <T> q;
        map <T, bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){

            T node = q.front();
            cout<<node<<" ";
            q.pop();

            // For the neighbours of the current node, find out the nodes which are not visited
            for(auto neighbour:adjList[node]){

                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

// Time O(V+E)
// Space O(V)
int main(){

    Graph <string>g;

    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Trump","Modi");
    g.addEdge("Prabhu","Yogi",true);
    g.addEdge("Prabhu","Modi",false);
    g.addEdge("Yogi","Modi");
    
    g.printAdjList();
    g.bfs("Putin");
    cout<<endl<<endl;
    
    Graph <int> g2;

    g2.addEdge(0,1);
    g2.addEdge(0,4);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    g2.addEdge(3,5);
    
    g2.printAdjList();
    g2.bfs(0);
    return 0;
}