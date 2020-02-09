#include <iostream>
#include <algorithm>
using namespace std;

int memo[1000];

// purely Dp (bottom-up approach)
// O(N)
int fibonacci(int n){

    int dp[1000] = {};
    
    dp[0] = 0;
    dp[1] = 1;
    for(int currNum=2; currNum<=n; currNum++){
        dp[currNum] = dp[currNum-1] + dp[currNum-2];
    }
    return dp[n];
}

// memoization (top-down approach)
// O(N)
// int fibonacci(int n){

//     if(n == 0 || n == 1){
//         return n;
//     }
//     if(memo[n] != -1){
//         return memo[n];
//     }
//     int ans = fibonacci(n-1) + fibonacci(n-2);
//     memo[n] = ans;
//     return memo[n];
// }

// purely recursion
// O(2^N)
// int fibonacci(int n){

//     if(n == 0 || n == 1){
//         return n;
//     }
//     int ans = fibonacci(n-1) + fibonacci(n-2);
//     return ans;
// }

int main(){
    
    int n;
    cin>>n;

    fill(memo, memo + n + 1, -1); //emptying my memopad
    
    int ans = fibonacci(n);
    cout<<ans;
    return 0;
}