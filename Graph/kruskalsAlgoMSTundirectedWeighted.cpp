#include <iostream>
#include <algorithm>
using namespace std;

class Edge{

    public:
    int src, dest, weight;
};

class Set{

    public:
    int rank, parent;
};

int find(Set *set, int i){

    if(set[i].parent != i){
        set[i].parent = find(set, set[i].parent);
    }
    return set[i].parent;
}

void Union(Set *set, int v1, int v2){

    int v1_root = find(set, v1);
    int v2_root = find(set, v2);

    if(set[v1_root].rank < set[v2_root].rank){
        set[v1_root].parent = v2_root;
    }
    else if(set[v1_root].rank > set[v2_root].rank){
        set[v2_root].parent = v1_root;
    }
    else{
        set[v2_root].parent = v1_root;
        set[v1_root].rank++;
    }
}

bool cmp(Edge e1, Edge e2){

    return e1.weight < e2.weight;
}

void krushals(Edge *edge, int v, int e){

    sort(edge, edge + e, cmp); // It will sort input array on the basis of weights of the edges

    Edge *output = new Edge[v-1]; // Initialised an output aarray

    Set *set = new Set[v];  // Initialised the set for all vertices
    for(int i=0; i<v; i++){
        set[i].rank = 0;    // Assign the rank initially as 0 
        set[i].parent = i;  // Assigned the parent of all vertices that are intially in their individual set as the vertex only 
    }

    int counter = 0, i = 0;
    while(counter < v-1){
        Edge currentEdge = edge[i]; // we have taken the edge with minimum weight
        int sourceParent = find(set, currentEdge.src);  // found the parent of source vertex
        int destinationParent = find(set, currentEdge.dest); // found the parent of destination vertex

        if(sourceParent != destinationParent){  // if both these lie in the same Set or not
            output[counter] = currentEdge;  // we will insert the edges in MST 
            Union(set, sourceParent, destinationParent);   // then we will union the sets of source and destination vertex
            counter++;  // increase the counter
        }
        i++;

    }
    for(int m=0; m<v-1; m++){
        cout<<output[m].src<<" -- "<<output[m].dest<<" with weight "<<output[m].weight<<endl;
    }
    int totalWeight = 0;
    for(int m=0; m<v-1; m++){
        totalWeight+= output[m].weight;
    }
    cout<<"totalWeight: "<<totalWeight<<endl;
}

int main(){

    int v, e;
    cin>>v>>e;

    Edge *edge = new Edge[e];
    for(int i=0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;

        edge[i].src = s;
        edge[i].dest = d;
        edge[i].weight = w;

    }
    krushals(edge, v, e);
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