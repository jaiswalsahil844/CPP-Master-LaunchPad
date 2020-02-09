#include <iostream>
#include <cstring>
using namespace std;

int memo[100][100];

// purely dp
// O(N^2)
int minCost(int grid[][100], int m ,int n){

    int dp[100][100] = {};
    
    // base case
    dp[0][0] = grid[0][0];
    // fill the first col
    for(int i=1; i<m; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    // fill the first row
    for(int j=1; j<n; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i=1; i<m ; i++){
        for(int j=1; j<n; j++){

            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];  // upward and left
        }
    }
    return dp[m-1][n-1];
}

// memoization 
// O(N^2)
// int minCost(int grid[][100], int m, int n){

//     if(m < 0 || n < 0){
//         return INT32_MAX;
//     }
//     if(m == 0 && n == 0){
//         return grid[m][n];
//     }

//     if(memo[m][n] != -1){
//         return memo[m][n];
//     }
//     int q1 = minCost(grid, m-1, n);
//     int q2 = minCost(grid, m ,n-1);

//     int ans = min(q1, q2) + grid[m][n];
//     memo[m][n] = ans;
//     return ans;
// }

// recursion
// O(2^N)
// int minCost(int grid[][100], int m, int n){

//     if(m < 0 || n < 0){
//         return INT32_MAX;
//     }

//     if(m == 0 && n == 0){
//         return grid[m][n];
//     }
//     int q1 = minCost(grid, m-1, n);
//     int q2 = minCost(grid, m ,n-1);

//     int ans = min(q1, q2) + grid[m][n];
//     return ans;
// }

int main() {

    int grid[100][100];
    int m,n;
    cin>>m>>n;

    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }

    memset(memo, -1, sizeof(memo));

    int ans = minCost(grid, m-1 , n-1);
    cout<<ans;
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}