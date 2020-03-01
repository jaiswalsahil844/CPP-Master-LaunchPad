#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#define int int
using namespace std;

int32_t main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int k;
    cin>>k;
    
    queue <int> q;
    int maximum = -1;
    for(int i=0; i<k; i++){
        q.push(arr[i]);
        maximum = max(maximum, arr[i]);
    }
    cout<<maximum<<" ";

    for(int i=k; i<n; i++){

        int x = q.front();
        q.pop();
        
        q.push(arr[i]);

        if(x == maximum){
            int y = -1;
            for(int j=i; j>i-k; j--){
                y = max(y, arr[j]);
            }
            maximum = y;
            
        }
        else{
            maximum = max(maximum, arr[i]);
        }
        cout<<maximum<<" ";
    }
    return 0;
}