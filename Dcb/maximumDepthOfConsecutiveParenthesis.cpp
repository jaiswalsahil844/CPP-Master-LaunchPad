#include <bits/stdc++.h>
#include <cstring>
#include <stack>
#define int int
using namespace std;

int32_t main(){

    int t;
    cin>>t;

    while (t--){
        
        stack <int> s;
        string str;
        
        cin>>str;
        
        int l = str.length();
        
        bool f = true;
        int c = 0;
        int maxi = -1;
        for(int i=0; i<l; i++){

            char ch = str[i];
            if(ch == '('){
                s.push(ch);

                if(f != true){
                    f = true;
                    maxi = max(maxi, c);
                    c = 0;
                }
                
            }
            else if(ch == ')'){
                
                if(s.empty()){
                    maxi = -1;
                    f = true;
                    break;
                }
                s.pop();
                c++;
                f = false;
            }
        }
        if(f != true){
            maxi = max(maxi, c);
        }
        
		if(!s.empty()){
			cout<<-1<<endl;
		}else{
			cout<<maxi<<endl;
		}
        
        
    }
    
}