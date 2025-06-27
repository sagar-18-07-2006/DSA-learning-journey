#include<iostream>
using namespace std;
int factorial(int n){
  
    if (n==0){
        return 1;
    }
    if (n==1){
        return 1;
    }
    if(n>1){

        return n*factorial(n-1);
    }
}
int main()
{
        int n;
    std::cout<<"enter thr number to find you want factorial: ";
   std::  cin>>n;
    std::cout<<"the factorial of "<<n<<" is "<<factorial(n);
}