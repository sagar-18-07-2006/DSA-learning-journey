#include <iostream>
using namespace std;

bool palindrome( string& s,int i=0){
    
    // Base Condition
    // If i exceeds half of the string means all the elements 
    // are compared, we return true.
    if(i>=s.length()/2) return true;
    
    // If the start is not equal to the end, not the palindrome.
    if(s[i]!=s[s.length()-i-1]) return false;
    
    // If both characters are the same, increment i and check start+1 and end-1.
    return palindrome(s,i+1);
}

int main() {
	
	// Example string.
	string s ;
     getline(cin,s);
	cout<<palindrome(s);
	cout<<endl;
	return 0;
}