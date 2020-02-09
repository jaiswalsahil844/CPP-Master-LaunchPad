#include <iostream>
#include <algorithm>
using namespace std;

// pure Dp
// O(N^2)
int lis(int *arr, int n){

    int dp[100];

    // base case
    fill(dp, dp + n, 1);
    
    int best = INT32_MIN;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){

            if(arr[i] >= arr[j]){   // jth element can be absorbed by ith element
                int currlen = 1 + dp[j];
                dp[i] = max(currlen, dp[i]);
            }
        }

        best = max(best, dp[i]);
    }
    return best;

}

int main() {
    
    int arr[100];
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = lis(arr, n);
    cout<<ans;
    return 0;
}