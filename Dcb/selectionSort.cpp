#include <iostream>
#define int int
using namespace std;

void selectionSort(int *arr, int n){

    for(int i=0; i<n-1; i++){
        int min_index = i;
        for(int j=i+1; j<n; j++){
            
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

int32_t main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selectionSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}