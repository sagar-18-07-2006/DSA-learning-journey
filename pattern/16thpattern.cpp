#include<iostream>
using namespace std;

int main(){
    cout << "Enter the no of rows " << endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {   
        char ch = 'A';

        // Print spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // Print increasing characters
        for (int j = 0; j <= i; j++)
        {
            cout << (char)(ch + j);
        }

        // Print decreasing characters
        for (int j = i - 1; j >= 0; j--)
        {
            cout << (char)(ch + j);
        }

        cout << endl;
    }

    return 0;
}
