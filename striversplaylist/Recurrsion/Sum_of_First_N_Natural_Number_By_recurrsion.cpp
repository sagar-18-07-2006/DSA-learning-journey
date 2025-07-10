#include <iostream>
using namespace std;
int sum =0;
int sum_Of_first_N_Numbers(int n,int sum=0)
{ 
    if(n<1){
        return sum  ;

    }
    // cout<<n<<" ";
   
   sum += sum_Of_first_N_Numbers(n-1,sum)+n;

}
int main()
{   int n;
    cout<<"Enter the number: ";
    cin>>n;
   cout<<sum_Of_first_N_Numbers(n)<<endl;
        return 0;
}