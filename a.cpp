#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
#include <map>
using namespace std;

int32_t main(){

    fast;
    fast_input;
    fast_output;
    int q;
    cin>>q;

    map<int, int> m;
    while(q--){

        string str;
        cin>>str;
        
        if(str == "Push"){
            int x;
            cin>>x;

            m[x] += 1;

        }else if(str == "Diff"){

            int diff = -1;
            int max;
            int min;
            if(!m.empty()){
                min = m.begin()->first;
                max = m.rbegin()->first;

                diff = max - min;

                if(max == min){
                    if(m.begin()->second == 1){
                        m.erase(m.begin());
                    }else{
                        m.begin()->second -= 1;
                    }
                }else{
                    if(m.begin()->second == 1){
                        m.erase(m.begin());
                    }else{
                        m.begin()->second -= 1;
                    }
                    if(m.rbegin()->second == 1){
                        auto it = m.find(m.rbegin()->first);
                        m.erase(it);
                    }else{
                        m.rbegin()->second -= 1;
                    }  
                }
                
            }
            cout<<diff<<endl;

        }else if(str == "CountHigh"){

            int count = -1;
            if(!m.empty()){
                count = m.rbegin()->second;
            }          
            cout<<count<<endl;

        }else if(str == "CountLow"){
            
            int count = -1;
            if(!m.empty()){
                count = m.begin()->second;
            }     
            cout<<count<<endl;

        }
    }
    return 0;
}