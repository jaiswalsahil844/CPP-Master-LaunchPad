#include <iostream>
#include <list>
#define inf 1e9
using namespace std;

class Graph{

    int V;
    list < pair <int, int> > *l;
    
    public:
    Graph(int V){
        this->V = V;
        l = new list < pair<int, int> > [V];
    }

    void addEdge(int u, int v, int w){
        
        l[u].push_back(make_pair(v, w));
        l[v].push_back(make_pair(u, w));

    }

    void printAdjList(){
        
        for(int i=0; i<V; i++){

            cout<<i<<" -> ";
            // l[i] is a linked list
            for(auto vertex: l[i]){
                cout<<vertex.first<<" "<<vertex.second<<" -> ";
            }
            cout<<endl;
        }
    }

    int findMinVertex(int *weight, bool *visited, int V){

        int minIndex = -1;

        for(int i=0; i<V; i++){
            if(!visited[i] and (minIndex == -1 or weight[i] < weight[minIndex])){
                minIndex = i;
            }
        }
        return minIndex;
    }

    void primsAlgo(){

        bool *visited = new bool[V];
        int *parent = new int [V];
        int *weight = new int [V];

        for(int i=0; i<V; i++){

            visited[i] = false; // mapping for vertices that has been visited
            weight[i] = inf;
        }
        
        parent[0] = -1;
        weight[0] = 0;

        for(int i=0; i<V; i++){

            int minVertex = findMinVertex(weight, visited, V);
            visited[minVertex] = true;  

            for(auto neighbours: l[minVertex]) {

                if(!visited[neighbours.first]){

                    if(weight[neighbours.first] > neighbours.second){   // If the weight for a vertex in our mapping is greater than the weight at the particualar edge or not
                        parent[neighbours.first] = minVertex;
                        weight[neighbours.first] = neighbours.second;
                    }

                }
            }   

        }
        for(int i=0; i<V; i++){
            cout<<i<<" -- "<<parent[i]<<" with weight "<<weight[i]<<endl;
        }

    }
};

int main(){


    int v, e;
    cin>>v>>e;

    Graph g(v);

    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;

        g.addEdge(u, v, w);
    }
    
    g.printAdjList();
    g.primsAlgo();

    return 0;
}
/*
7 8
0 3 4
0 1 6 
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3
*/