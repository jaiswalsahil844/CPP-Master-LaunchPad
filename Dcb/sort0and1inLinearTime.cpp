#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int s = 0;
    int e = n-1;
    while(s <= e){
        if(arr[s] == 0){
            s++;
        }
        else{
            if(arr[e] == 1){
                e--;
            }
            else{
                swap(arr[s], arr[e]);
                s++;
                e--;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}