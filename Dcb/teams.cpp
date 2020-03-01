#include <iostream>
#define int long long
using namespace std;

int32_t main(){
    
    int n,m;
    cin>>n>>m;

    int x = n - (m-1);
    int max = (x*(x-1))/2;

    int y = n/m;
    int rem = n%m;

    int min = (m - rem)*(y*(y-1))/2 + rem*((y+1)*y)/2 ;

    cout<<min<<" "<<max<<endl;
    return 0;
}