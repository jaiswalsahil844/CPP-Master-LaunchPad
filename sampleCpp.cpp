#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL) 
using namespace std;

void fastscan(int &number);
int32_t main(){
	
	fast;
	fast_input;
	fast_output;
	
    int n;
	fastscan(n);
	while(n--){
		
        
	}
	cout<<"\n";
	return 0;	
}

void fastscan(int &number){

    // Syntax is same as getchar() 
    // char c = getchar_unlocked(); 
    // putchar_unlocked(c); 

	//variable to indicate sign of input number 
	bool negative = false; 
	register int c; 

	number = 0; 

	// extract current character from buffer 
	// c = getchar(); 
    c = getchar_unlocked();
	if (c=='-') 
	{ 
		// number is negative 
		negative = true; 

		// extract the next character from the buffer 
		// c = getchar(); 
        c = getchar_unlocked();
	} 

	// Keep on extracting characters if they are integers 
	// i.e ASCII Value lies from '0'(48) to '9' (57) 
	for (; (c>47 && c<58); c = getchar_unlocked()) 
		number = number *10 + c - 48; 

	// if scanned input has a negative sign, negate the 
	// value of the input number 
	if (negative) 
		number *= -1; 
} 
