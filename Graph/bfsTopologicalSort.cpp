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
    void bfsTopologicalSort(){

        queue <T> q;
        map <T, bool> visited;
        map <T, int> indegree;

        for(auto i: adjList){
            // i is pair of node and its list
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;  
        }
        // Init the indegress of all nodes
        for(auto i: adjList){
            T u = i.first;
            for(auto v: adjList[u]){
                indegree[v]++;
            }
        }
        // Find out all the nodes with 0 degree
        for(auto i: adjList){
            T node = i.first;
            if(indegree[node] == 0){
                q.push(node);
            }
        }
        // Start with algorithm
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" -> ";

            for(auto neighbour: adjList[node]){
                indegree[neighbour]--;

                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

    }
};

// Kahn's Algorithms
int main(){


    Graph <string> g;

    g.addEdge("English", "Programming Logic", false);
    g.addEdge("English", "HTML", false);
    g.addEdge("Maths", "Programming Logic", false);
    g.addEdge("Programming Logic", "HTML", false);
    g.addEdge("Programming Logic", "Python", false);
    g.addEdge("Programming Logic", "Java", false);
    g.addEdge("Programming Logic", "JS", false);   
    g.addEdge("Python", "Wev Dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web dev", false);
    g.addEdge("Java", "Web dev", false);
    
    g.printAdjList();
    g.bfsTopologicalSort();
    
    return 0;
}