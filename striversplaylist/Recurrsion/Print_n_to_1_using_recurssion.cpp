#include <iostream>
using namespace std;

void peint(int n)
{
    if(n<1){
        return ;

    }
    cout<<n<<" ";
   
    peint(n-1);

}
int main()
{   int n;
    cout<<"Enter the number: ";
    cin>>n;
    peint(n);
        return 0;
}