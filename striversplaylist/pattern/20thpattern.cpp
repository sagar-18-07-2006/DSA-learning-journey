#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of Rows: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i*j==0){
                cout<<"* ";
            }
            else if (j==n-1)
            {
                cout<<"* ";
                /* code */
            }
            else if (i==n-1)
            {
                cout<<"* ";
                /* code */
            }
            
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}