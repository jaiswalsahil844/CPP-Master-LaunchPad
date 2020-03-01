#include <iostream>
#include <cstring>
using namespace std;

int n = 4;
int dp[16][4];

// Adj Matrix which defines the graph
int dist[][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
}; 

// If all cities have been visted
int visited_all = (1<<n) - 1;

int tsp(int mask, int pos){

    if(mask == visited_all){
        return dist[pos][0];
    }

    // Lookup
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }

    int ans = INT32_MAX;
    // Try to goto an unvisited city
    for(int city=0; city<n; city++){

        if((mask & (1<<city)) == 0){
            
            int newAns = dist[pos][city] + tsp((mask | (1<<city)), city);
            ans = min(ans, newAns);
        }
    }
    dp[mask][pos] = ans;
    return ans;
}

// O((2^N).N)
int main(){

    memset(dp, -1, sizeof(dp));
    cout<<"Min weight hamiltonian path costs "<<tsp(1, 0);
    return 0;
}