#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int arr[] = {1, 3, 4, 1, 8, 74, 9, 3, 97};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n-1; i >0; i--)
    {
        int maxindex = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[maxindex])
                maxindex = j;
        }
        if (maxindex != i)
            swap(arr[i], arr[maxindex]);
    }

        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
            cout << endl;
        }

    return 0;
}
