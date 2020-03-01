#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

// Naive Approach O(N)
bool isPrime(int n){
    
    if(n == 1 || n == 0){
        return false;
    }
    for(int i=2; i<n; i++){  // i<=n/2 or i*i <= n
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

// Seive Approach O() - Genrate a array containng prime numbers
void prime_seive(int *p){

    // first mark all odd number's prime
    for(int i=3; i<=1000000; i+=2){
        p[i] = 1;
    }
    // Seive
    for(int i=3; i<=100000; i+=2){
        // if the current number is not marked (it is prime)
        if(p[i] == 1){

            for(int j=2*i ; j<=1000000; j+= i){
                p[j] = 0;
            }
        }
    }
    // special case
    p[2] = 1;

}

int32_t main(){

    fast;
    fast_input;
    fast_output;

    int p[1000006] = {0};
    
    prime_seive(p);

    int n;
    cin>>n;

    // for(int i=0; i<=n; i++){
    //     if(isPrime(i)){
    //         cout<<i<<" ";
    //     }
    // }
    
    // lets print primes upto range n 
    for(int i=0; i<=n; i++){
        if(p[i] == 1){
            cout<<i<<" ";
        }
    }
    return 0;

}