#include <iostream>
using namespace std;
// int cnt =1;
void peint(int n,int cnt =1)//bot ways are possible 
{
    if(cnt>n){
        return ;

    }
    cout<<cnt<<" ";
    cnt++;
    peint(n,cnt);

}
int main()
{   int n;
    cout<<"Enter the number: ";
    cin>>n;
    peint(n);
        return 0;
}