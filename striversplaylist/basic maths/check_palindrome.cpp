#include <iostream>
// #include <vector>
#include <string>
using namespace std;
bool Palindrome_checker(int n)
{
    int temp =n;
    int reversedNumber = 0;

    while (n != 0)
    {
        int b = n % 10;
        reversedNumber = (reversedNumber * 10) + b;
        n = n / 10;
    }
    bool ans = false;
    if (reversedNumber ==temp)
    {
        ans = true;
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter your number: ";
    cin >> n;
    cout << Palindrome_checker(n);
}