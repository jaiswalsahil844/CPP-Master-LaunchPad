#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

int gcd(int a, int b){

    if(b == 0){
        return a;
    }
    int ans = gcd(b, a%b);
    return ans;
}

int32_t main(){

    fast;
    fast_input;
    fast_output;
    
    int a,b;
    cin>>a>>b;

    int ans = gcd(a, b);
    cout<<ans;
    return 0;

}