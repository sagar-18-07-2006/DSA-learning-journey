#include <iostream>
#include<climits>
#include<math.h>
using namespace std;

int main() {
    int n;
    cout<<"enter the size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:we will not add value more than 13
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }
    cout<<"enter the number of query you want to check"<<endl;
    int q;
    cin >> q;
    while (q--) {
        int number;
        cout<<"Enter the querry:";
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    return 0;
}