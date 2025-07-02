#include<iostream>
using namespace std ;
int main(){
    cout<<"Enter the number  of rows"<<endl;
    int n;
    cin>>n;
 
    for (int  i = 0; i < n; i++)
    {
       for(int j=0;j<=i;j++){
        cout<<"*";
       }
       for(int j=i;j<n-1;j++){
           cout<<" ";
        }
     
        
            /* code */
            for(int j=i;j<n-1;j++){
                cout<<" ";
            }
        
        
        for(int j=0;j<=i;j++){
         cout<<"*";
        }
        cout<<endl;
        
    }
    for (int  i = 1; i < n; i++)
    {
       for(int j=0;j<n-i;j++){
        cout<<"*";
       }
       for(int j=0;j<i;j++){
           cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
         cout<<"*";
        }
     
        
            /* code */
            
        
        
       
        cout<<endl;
        
    }
    return 0;
}