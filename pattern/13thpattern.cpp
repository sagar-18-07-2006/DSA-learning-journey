#include <iostream>
using namespace std;

int main()
{
    cout << "enter no of rows: ";
    int n;
    cin >> n;
    int b=1;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<i+1;j++){
            cout<<b<<" ";
            b++;
        }
        cout<<endl;
    }
    return 0;
}