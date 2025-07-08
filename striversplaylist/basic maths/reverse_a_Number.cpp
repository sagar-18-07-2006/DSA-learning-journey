#include <iostream>
// #include <vector>

using namespace std;
int Reverse_A_Number(int n)
{
    int reversedNumber =0;

    while (n != 0)
    {
        int b=n%10;
        reversedNumber= (reversedNumber*10)+b;
        n=n/10;

    }
    return reversedNumber;
}
int main()
{
    int n;
    cout << "enter your number: ";
    cin >> n;
    cout<<Reverse_A_Number(n);
}