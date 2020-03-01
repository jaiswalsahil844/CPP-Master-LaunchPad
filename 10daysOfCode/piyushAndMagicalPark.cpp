#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
using namespace std;

void magicalPark(char arr[][100], int n, int m ,int k, int s){

    bool flag = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(k > s){
                flag = false;
                break;
            }
            if(arr[i][j] == '.'){
                s -= 2;
            }else if(arr[i][j] == '*'){
                s += 5;
            }else if(arr[i][j] == '#'){
                break;
            }

            if(j != m-1){
                s -= 1;
            }
        }
    }
    if(flag){
        cout<<"Yes"<<endl<<s;
    }else{
        cout<<"No"<<endl;
    }

}

int32_t main(){

    fast;
    fast_input;
    fast_output;

    int n,m,k,s;
    cin>>n>>m>>k>>s;

    char arr[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            cin>>arr[i][j];
        }
    }

    magicalPark(arr, n, m, k, s);

    return 0;

}