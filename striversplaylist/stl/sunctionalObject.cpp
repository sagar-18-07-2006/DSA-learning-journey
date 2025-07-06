#include <iostream>
#include<functional>
#include<algorithm>

using namespace std;
int main()
{
  int arr1 []={1,3,4,12,54,7};
    sort(arr1,arr1+5);
    int n=sizeof(arr1)/sizeof(arr1[0]);
    sort(arr1,arr1+n);
    for (int i = 0; i <n; i++)
    {
        cout<<arr1[i]<<endl;
        /* code */
    }
    sort(arr1,arr1+n,greater<int>
    ());
    for (int i = 0; i <n; i++)
    {
        cout<<arr1[i]<<endl;
        /* code */
    }
    
}