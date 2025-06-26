#include<iostream>
int fibonociSeries(int n){
    if (n==1){
    return 1;
    }
    if (n==0){
    return 0;
    }
    if(n>1){
        return (fibonociSeries(n-1)+fibonociSeries(n-2));
    }
}
int main(){
    int n;
    std::cout<<"enter thr number of series you print: ";
   std::  cin>>n;
    std::cout<<"the fiboonoci of "<<n<<" is "<<fibonociSeries(n);
}