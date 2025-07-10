#include<iostream>
using namespace std;


int main (){  
    cout << "enter no of rows: ";
    int n;
    cin >> n;
    char ch='A';
    for (int i = 0; i <  n; i++)
    {
        for (char j='A';j<'A'+i+1;j++){
            cout<<ch;
        }
        cout<<endl;
        ch++;
        
        
    
}
return 0;
}