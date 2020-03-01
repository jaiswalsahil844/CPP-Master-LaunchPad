#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Graph{

    list <pair <T, T> > l;

    public:
    Graph(){

    }

    void addEdge(T u, T v, bool bidir=true){

        l.push_back(make_pair(u,v));
        if(bidir){
            l.push_back(make_pair(v,u));
        }
    }

    void printEdgeList(){
        
        for(auto i: l){
            
            cout<<i.first<<" -> "<<i.second<<endl;

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
    
    g.printEdgeList();
    cout<<endl;

    Graph <int> g2;

    g2.addEdge(0,1);
    g2.addEdge(0,4);
    g2.addEdge(1,2);
    g2.addEdge(1,3); 
    g2.addEdge(1,4);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    
    g2.printEdgeList();
    return 0;
}