#include<iostream>
using namespace std;


int main (){  
    cout << "enter no of rows: ";
    int n;
    cin >> n;
    for (int i = 0; i <  n; i++)
    {
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        for(int j=n;j>i+1;j--){
            cout<<" ";
        }
        cout<<endl;
        
    }
    for (int i = 1; i < n; i++)
    {
        /* code */
        
        for(int j=n;j>i;j--){
            cout<<"*";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
return 0;
}