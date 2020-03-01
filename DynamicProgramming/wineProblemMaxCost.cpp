#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int cnt = 0;
int memo[100][100];

// purely Dp
// O(N^2)
int maxProfit(int *arr, int n){

    int dp[100][100] = {};
    int year = n;
    
    for(int i=0; i<n; i++){
        dp[i][i] = arr[i]*year;

    }
    year--;
    for(int len=2; len<=n; len++){

        int s = 0;
        int e = n - len;

        while(s <= e){
            int endWindow = s + len - 1;
            
            dp[s][endWindow] = max(dp[s+1][endWindow] + arr[s]* year, dp[s][endWindow-1] + arr[endWindow]*year);
            s++;
        }
        year--;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<setw(3)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];

}

// memoization
// O(N^2)
// int maxProfit(int arr[], int s, int e, int year){

//     cnt++;
//     if(s > e){
//         return 0;
//     }
    
//     if(memo[s][e] != -1){
//         return memo[s][e];
//     }

//     int q1 = arr[s]*year + maxProfit(arr, s+1, e, year+1);  // sell from beg
//     int q2 = arr[e]*year + maxProfit(arr, s, e-1, year+1);  // sell from end

//     int ans = max(q1, q2);
//     memo[s][e] = ans;
//     return ans;

// }

// purely recursion
// O(2^N)
// int maxProfit(int arr[], int s, int e, int year){

//     cnt++;
//     if(s > e){
//         return 0;
//     }

//     int q1 = arr[s]*year + maxProfit(arr, s+1, e, year+1);  // sell from beg
//     int q2 = arr[e]*year + maxProfit(arr, s, e-1, year+1);  // sell from end

//     int ans = max(q1, q2);
//     return ans;

// }

int main(){

    int arr[100];    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    memset(memo, -1, sizeof(memo));

    // int ans = maxProfit(arr, 0, n-1, 1);
    int ans = maxProfit(arr, n);
    cout<<ans<<endl;
    // cout<<cnt;
    return 0;
}