#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

int traillingZeroes(int n){

    int ans = 0;
    int p = 5;
    while((n/p) != 0){

        ans += n/p;
        p *= 5;
    }
    return ans;

}

int32_t main(){

    fast;
    fast_input;
    fast_output;

    int n;
    cin>>n;

    int ans = traillingZeroes(n);
    cout<<ans;
    return 0;

}