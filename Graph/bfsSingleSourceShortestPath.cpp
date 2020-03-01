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
        map <T, int> dist;
        map <T, T> parent;

        for(auto i: adjList){
            dist[i.first] = int32_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()){

            T node = q.front();
            cout<<node<<" ";
            q.pop();

            // For the neighbours of the current node, find out the nodes which are not visited
            for(auto neighbour:adjList[node]){

                if(dist[neighbour] == int32_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        // Print the distance to all the nodes
        for(auto i: adjList){
            T node = i.first;
            cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
    }
};

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
    cout<<endl;
    g.bfs("Putin");
    cout<<endl;

    Graph <int> g2;

    g2.addEdge(0,1);
    g2.addEdge(0,4);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    g2.addEdge(3,5);
    
    g2.printAdjList();
    cout<<endl;
    g2.bfs(0);
    return 0;
}