#include <iostream>
#define int long long 
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

int pairFrds(int n){

    if(n == 1 || n == 2){
        return n;
    }

    int ans = pairFrds(n-1) + (n-1)*pairFrds(n-2);
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

        cout<<pairFrds(n)<<endl;
    }
    return 0;

}