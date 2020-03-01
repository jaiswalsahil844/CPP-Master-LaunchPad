#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

void prime_seive(int *p){

    for(int i=3; i<=1000000; i+=2){
        p[i] = 1;
    }
    
    for(int i=3; i<=1000000; i+=2){
        
        if(p[i] == 1){

            for(int j=i*i ; j<=1000000; j+= i){    
                p[j] = 0;
            }
        }
    }

    p[2] = 1;

}

int32_t main(){

    fast;
    fast_input;
    fast_output;

    int p[1000006] = {0};
    
    prime_seive(p);
    
    int csum[1000006] = {0};

    // precompute the primes upto an index i
    for(int i=1; i<=1000000; i++){
        csum[i] = csum[i-1] + p[i];
    }

    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;

        cout<<(csum[b] - csum[a-1])<<endl;

    }
    return 0;

}
