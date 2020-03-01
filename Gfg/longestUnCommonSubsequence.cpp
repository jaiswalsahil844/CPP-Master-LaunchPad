#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// O(min(x, y))
int findLUSlength(string a, string b){

    if(a == b){
        return -1;
    }

    return max(a.length(), b.length());
    
}

// O(2^x + 2^y)
int findLUSlength(string a, string b){

    if(a == b){
        return -1;
    }

    unordered_map <string, int> map;
    vector <string> strArr;

    strArr.push_back(a);
    strArr.push_back(b);

    for(string s: strArr){

        for(int i=0; i< (1<<s.length()); i++){

            string t = "";
            for(int j=0; j<s.length(); j++){

                if(((i>>j) & 1) != 0){
                    t += s[j];
                }
            }
            
            if(map.count(t)){
                map[t]++;
            }
            else{
                map[t] = 1;
            }
        }
    }
    int res = -1;
    for(auto a: map){

        if(a.second == 1){
            res = max(res, (int)a.first.length());   // typecast
        }
    }
    return res;
}

int main(){

    string a,b;
    cin>>a>>b;

    int ans = findLUSlength(a, b);
    cout<<ans<<endl;

    return 0;
}