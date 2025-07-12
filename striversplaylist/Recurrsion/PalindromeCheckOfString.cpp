#include <iostream>
#include <string>
using namespace std;
string reverseString(string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (end > start)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    return str;
}
bool PalindromeCheck(string str)
{
    string reverseStr = reverseString(str);
    if (str == reverseStr)
    {
        return true;
    }
    else
    {
       return false;
    }
}
int main(){
    string str;
    getline(cin,str);
   cout<<str <<" is "<<PalindromeCheck(str)<<" ";
    
}