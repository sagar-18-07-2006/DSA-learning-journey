#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;// it have time compleexity of O(n) and space c omplexity of O(n) but for loop will have space complexity of O(i and time complexity is same )
    }
    else{ 
        return (n*factorial(n-1));
    }
}

int main (){
    int n;
    cout<<"Enter the number: ";
    cin >> n;
    cout<<"The factorial of "<<n<<" is "<<factorial(n);
    return 0;
}