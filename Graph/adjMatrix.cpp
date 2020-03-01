#include <iostream>
#include <cstring>
using namespace std;

class Graph{

    int V;
    int **arr;

    public:
    Graph(int V){

        this->V = V;

        arr = new int* [V];
        for(int i=0; i<V; i++){
            arr[i] = new int[V];
            memset(arr[i], 0, sizeof(arr));
        }
        
    }

    void addEdge(int u, int v,int weight=1, bool bidir=true){

        arr[u][v] = weight;
        if(bidir){
            arr[v][u] = weight;
        }

    }

    void printAdjMatrix(){

        for(int i=0; i<V; i++){

            cout<<i<<" -> ";
            for(int j=0; j<V; j++){

                if(arr[i][j] == 1){
                    cout<<j<<", ";
                }

            }
            cout<<endl;
        }
    }    

};

int main(){
    
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3); 
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    
    g.printAdjMatrix();
    return 0;
}