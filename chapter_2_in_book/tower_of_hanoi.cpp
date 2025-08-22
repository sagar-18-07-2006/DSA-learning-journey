#include<iostream>
using namespace std;
void TOH(int n,char A,char B,char C){
    if(n==1){
       std:: cout<<"Move disk 1 from "<<A<<" to "<<C<<endl;
    }
    else{
    TOH(n-1, A, C, B);
   cout<<"Move disk "<< n<<" from " <<A<<" to"<< C<<endl;
    TOH(n-1, B, A, C);}
}
int main(){
      int n;
    std::cout<<"enter thr number of series you print: ";

   std::  cin>>n;f
    TOH(n,'S','A','D');
}
// TOH(N, A, B, C)
//   if N == 1:
//     Move disk 1 from A to C
//   else:
//     TOH(N-1, A, C, B)
//     Move disk N from A to C
//     TOH(N-1, B, A, C)
