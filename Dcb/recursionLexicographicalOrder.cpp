#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#define int int
using namespace std;

bool compare(string a, string b){
    return a < b;
}

int32_t main(){

    int n;
    cin>>n;

    string str[n+1];
    for(int i=0; i<=n; i++){
        str[i] = to_string(i);
    }

    sort(str, str + n + 1 , compare);

    for(int i=0; i<=n; i++){
        cout<<str[i]<<" ";
    }
    return 0;
}