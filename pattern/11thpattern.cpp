#include<iostream>
using namespace std;


int main (){  
    cout << "enter no of rows: ";
    int n;
    cin >> n;
    for (int i = 0; i <n; i++)
    {
         for(int j=0;j<i+1;j++){
            if((i+j)%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
         }
         cout<<endl;
    }
    
return 0;
}