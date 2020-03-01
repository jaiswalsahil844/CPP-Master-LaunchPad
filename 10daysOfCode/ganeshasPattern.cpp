#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

void ganeshasPattern(int n){

    cout<<"*";
    for(int i=0; i<(n-3)/2; i++){
        cout<<" ";
    }
    for(int i=0; i<(n+1)/2; i++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=0; i<(n-3)/2; i++){
        cout<<"*";
        for(int j=0; j<(n-3)/2; j++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=0; i<(n-3)/2; i++){
        for(int j=0; j<(n-3)/2+1; j++){
            cout<<" ";
        }
        cout<<"*";
        for(int j=0; j<(n-3)/2; j++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    for(int i=0; i<(n+1)/2; i++){
        cout<<"*";
    }
    for(int i=0; i<(n-3)/2; i++){
        cout<<" ";
    }
    cout<<"*";

}

int32_t main(){

    fast;
    fast_input;
    fast_output;

    int n;
    cin>>n;

    ganeshasPattern(n);
    return 0;

}