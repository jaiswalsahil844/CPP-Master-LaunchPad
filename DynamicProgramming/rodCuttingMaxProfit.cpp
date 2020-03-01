#include <iostream>
#include <algorithm>
using namespace std;

int memo[100];

// purely Dp
// O(N^2)
int maxProfit(int *arr, int totalLen){

    int dp[100] = {};
    
    for(int len = 1; len<= totalLen; len++){
        int best = 0;
        for(int cut = 1; cut <= len; cut++){

            best = max(best, arr[cut] + dp[len - cut]);
        }
        dp[len] = best;
    }
    return dp[totalLen];
}

// memoization
// O(N^2)
// int maxProfit(int *arr, int totalLen){
    
//     if(totalLen == 0){
//         return 0;
//     }
//     if(memo[totalLen] != -1){
//         return memo[totalLen];
//     }
//     int best = 0;
//     for(int len = 1; len <= totalLen; len++){
    
//         int netProfit = arr[len] + maxProfit(arr, totalLen - len);
//         best = max(best, netProfit);
//     }
//     memo[totalLen] = best;
//     return best;
// }

// purely recursion
// O(4^N)
// int maxProfit(int *arr, int totalLen){
    
//     if(totalLen == 0){
//         return 0;
//     }
    
//     int best = 0;
//     for(int len = 1; len <= totalLen; len++){
        
//         int netProfit = arr[len] + maxProfit(arr, totalLen - len);
//         best = max(best, netProfit);
//     }
//     return best;
// }

int main() {

    int price[100];
    int totalLen;
    cin>>totalLen;
    
    for(int eachPrice = 1; eachPrice <= totalLen; eachPrice++){
        cin>>price[eachPrice];
    }
    
    fill(memo, memo + totalLen + 1, -1);
    
    int ans = maxProfit(price, totalLen);
    cout<<ans;
    return 0;
}