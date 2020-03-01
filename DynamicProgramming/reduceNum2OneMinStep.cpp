#include <iostream>
#include <algorithm>
using namespace std;

const int inf = (int)1e9; // use instead of int32_MAX
int memo[10000];

// purely Dp
// O(N)
int reduceNum(int n){

    int dp[10000] = {};

    // setting the base case
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    // compute the ans for n
    for(int currNum=4; currNum<=n; currNum++){
        
        int q1 = inf, q2 = inf, q3 = inf;
        if(currNum%3 == 0){
            q1 = 1 + dp[currNum/3];
        }
        if(currNum%2 == 0){
            q2 = 1 + dp[currNum/2];
        }
        q3 = 1 + dp[currNum-1];
        
        dp[currNum] = min(q1, min(q2, q3));
    }
    return dp[n];
}

// memoization
// O(N)
// int reduceNum(int n){

//     if(n == 1){
//         return 0;
//     }

//     if(memo[n] != -1){
//         return memo[n]; // bcz this has already computed! No recomputation
//     }
    
//     int q1 = int32_MAX, q2 = int32_MAX, q3 = int32_MAX;
//     if(n%3 == 0){
//         q1 = 1 + reduceNum(n/3);
//     } 
//     if(n%2 == 0){
//         q2 = 1 + reduceNum(n/2);
//     }
//     q3 = 1 + reduceNum(n-1);

//     int ans = min(q1, min(q2, q3));
//     memo[n] = ans;  // memoize has to be done
//     return ans;
// }

// purely recursion
// O(3^N)
// int reduceNum(int n){

//     if(n == 1){
//         return 0;
//     }
    
//     int q1 = inf, q2 = inf, q3 = inf;
//     if(n%3 == 0){
//         q1 = 1 + reduceNum(n/3);
//     } 
//     if(n%2 == 0){
//         q2 = 1 + reduceNum(n/2);
//     }
//     q3 = 1 + reduceNum(n-1);

//     int ans = min(q1, min(q2, q3));
//     return ans;
// }
int main(){
    
    int n;
    cin>>n;

    fill(memo,memo + n + 1, -1);  // for loop

    int ans = reduceNum(n);
    cout<<ans;
    return 0;
}