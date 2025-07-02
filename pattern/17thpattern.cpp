#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the no of rows " << endl;
    int n;
    cin >> n;
    char ch ='A'+n-1;
    for (int i = 0; i <n; i++)
    { 
        for (int j = 0; j <= i; j++)
        {
            char temp = ch-j;
            cout<<temp<<" ";
        }
        cout<<endl;
    }

    return 0;
}
