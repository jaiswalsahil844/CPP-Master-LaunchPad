#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    string str;
    cin>>str;

    int l = str.length();
    for(int i=0; i<l; i++){

        if(i%2 == 0){
            str[i] = char(str[i] + 1);
        }else{
            str[i] = char(str[i] - 1);
        }
    }

    cout<<str;
    return 0;
}