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

    void dfsHelper(T node, map<T, bool> &visited, list <T> &ordering){

        // Whenever to come to a node, mark it visted 
        visited[node] = true;

        // will call dfs on the unvisted neighbours of the current node
        for(auto neighbour: adjList[node]){

            if(!visited[neighbour]){
                dfsHelper(neighbour, visited, ordering);
            }
        }
        // Add 1 line for Topological Sort
        // At this point, all the children of current node have been visited
        // so we can add current node to the list
        ordering.push_front(node);

    }

    void dfsTopologicalSort(){

        map <T, bool> visited;
        list <T> ordering;

        for(auto i: adjList){
            // i is pair (node, list of nodes)
            T node = i.first;
            if(!visited[node]){
                dfsHelper(node, visited, ordering);
            }
        }

        // Print all the elements in ordering
        for(auto element: ordering){
            cout<<element<<" -> ";
        }
    
    }
};


// O(V+E)
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
    g.dfsTopologicalSort();
    return 0;
}