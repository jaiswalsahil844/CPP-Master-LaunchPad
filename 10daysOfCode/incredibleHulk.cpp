#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

int countBits(int n){

    int ans = 0;
    while(n != 0){
        int last_bit = n&1;
        ans += last_bit;
        n = n>>1;
    }
    return ans;
}

int fastCountBits(int n){

    int ans = 0;
    while(n != 0){
        n = n&(n-1);
        ans++;
    }
    return ans;
}

int32_t main(){

    fast;
    fast_input;
    fast_output;
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        // int ans = countBits(n);
        // int ans = fastCountBits(n);
        int ans = __builtin_popcount(n);
        cout<<ans<<endl;
    }
    return 0;

}