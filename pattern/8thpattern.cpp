#include<iostream>
using namespace std;


int main (){  
    cout << "enter no of rows: ";
    int n;
    cin >> n;
    for (int i = 0; i <  n; i++)
    {
        if(i<n){
            for(int j=i;j<n-1;j++){
                cout<<" ";
                

            }
            for(int j=0;j<2*(i)+1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    //     else{
    //         for(int j=2*n;j<2*n+1;j++){
    //             cout<<" ";
                
    
    //         }
    //         for(int j =i;j<;j++){
    //             cout<<"*";
                
    //         }
    //         cout<<endl;
    // }
    }
    for (int i = 0; i < n; i++)
    {
        // cout<<" ";
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2*(n - i)-1; j++)
        {
            cout << "*";
        }
        cout << endl;
        
        
    
}
return 0;
}