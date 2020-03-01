#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

template <typename T>
class Graph{

    unordered_map <T , list < pair <T, int> > > m;

    public:
    Graph(){

    }

    void addEdge(T u, T v, int dist, bool bidir=true){
        
        m[u].push_back(make_pair(v, dist));
        if(bidir){
            m[v].push_back(make_pair(u, dist));
        }
    }

    void printAdjList(){
        
        // Let try to print the adj list
        // Iterate over all the key values pairs int the map
        for(auto i: m){

            cout<<i.first<<" -> ";
            for(auto l: i.second){
                cout<<"("<<l.first<<", "<<l.second<<")";
            }
            cout<<endl;
        }
        
    }
    void dijkstrasSSSP(T src){

        unordered_map <T, int> dist;

        unordered_map <T, T> parent;

        // Set all distacne to infinity
        for(auto i: m){
            dist[i.first] = INT32_MAX;
        }
        // Make a set to find a out node with minimum distacne
        set < pair <int, T> > s;

        dist[src] = 0;
        s.insert(make_pair(0, src));
        parent[src] = src;

        while(!s.empty()){

            // Find the pair at the front
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            // Iterate over neighbouring / children of the current node
            for(auto childPair: m[node]){

                if(nodeDist + childPair.second < dist[childPair.first]){

                    // In the set updation of a particular is not possible
                    // we have to remove the old pair, and insert the new pair to simulation updation
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));

                    if(f != s.end()){
                        s.erase(f);
                    }

                    // Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                    parent[childPair.first] = node;
                }
            }

        }
        // Lets print distance to all other node from src
        for(auto d: dist){
            cout<<d.first<<" is located at distance of "<<d.second<<" via ";
            T temp = d.first;

            while(temp != src){
                cout<<parent[temp]<<" <- ";
                temp = parent[temp];
            }
            cout<<endl;
        }
    }

};

// O(ElogV)
int main(){

    Graph <int> g;

    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);

    g.printAdjList();

    g.dijkstrasSSSP(1);
    cout<<endl;
                    
    Graph <string> india;

    india.addEdge("Amritsar", "Jaipur", 4);
    india.addEdge("Amritsar", "Delhi", 1);
    india.addEdge("Jaipur", "Delhi", 2);
    india.addEdge("Delhi", "Agra", 1);
    india.addEdge("Agra", "Bhopal", 2);
    india.addEdge("Bhopal", "Mumbai", 3);
    india.addEdge("Mumbai", "Jaipur", 8);

    india.printAdjList();

    india.dijkstrasSSSP("Amritsar");
    return 0;
}