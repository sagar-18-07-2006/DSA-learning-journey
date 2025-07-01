#include<iostream>
using namespace std;


int main (){  
    cout << "enter no of rows: ";
    int n;
    cin >> n;
    for (int i = 0; i <  n; i++)
    {
        for (char j='A';j<='A'+i;j++){
            cout<<j;
        }
        cout<<endl;
        
        
    
}
return 0;
}