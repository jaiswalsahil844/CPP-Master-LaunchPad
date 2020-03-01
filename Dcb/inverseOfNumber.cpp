#include <bits/stdc++.h>
#include <algorithm>
#define int int
using namespace std;

int32_t main(){

    
    int n;
    cin>>n;

    int num = 0;
    int x = 1;
    while(n != 0){

        int rem = (n % 10) - 1;
        num += x*(int)pow(10, rem);
        
        x++;
        n /= 10;
    }
    cout<<num<<endl;
    return 0;
}