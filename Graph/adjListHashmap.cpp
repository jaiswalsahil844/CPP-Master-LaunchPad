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
            // adjList[i.first] == i.second
            for(auto entry: adjList[i.first]){     // T == auto
                cout<<entry<<", ";
            }

            // typename list <T> :: iterator it;
            // for(it = i.second.begin(); it != i.second.end(); it++){
            //     cout<<*it<<", ";
            // }
            cout<<endl;
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

    Graph <int> g2;

    g2.addEdge(0,1);
    g2.addEdge(0,4);
    g2.addEdge(1,2);
    g2.addEdge(1,3); 
    g2.addEdge(1,4);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    
    g2.printAdjList();
    return 0;
}