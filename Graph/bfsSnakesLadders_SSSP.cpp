#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
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

    int bfs(T src, T dest){

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
        cout<<endl;
        // for(auto i: adjList){
        //     T node = i.first;
        //     cout<<"Dist of "<<node<<" is "<<dist[node]<<endl;
        // }

        // you can destination and go backwards
        // backtrack
        T temp = dest;
        while(temp != src){
            cout<<temp<<" <- ";
            temp = parent[temp];
        }
        cout<<src<<endl;
        
        return dist[dest];
    }
};

int main(){

    Graph <int> g;

    int board[37];
    fill(board, board + 37, 0);

    // ladders
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[25] = 10;
    // snakes
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[32] = -2;
    board[34] = -22;

    // lets first construct the graph, add pair of u,v
    for(int u=0; u<=36; u++){
        // at every node =, you can throw a dice
        for(int dice=1; dice<=6; dice++){
            int v = u + dice + board[u + dice];
            
            g.addEdge(u, v, false);
        }
    }
    cout<<g.bfs(0,36);
    return 0;
}

