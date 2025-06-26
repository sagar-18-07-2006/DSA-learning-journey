#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to reverse a portion of the vector
void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> a[i];
    }

    cout << "Enter steps to rotate: ";
    cin >> k;

    // Handle if k > n
    k = k % n;

    // 1. Reverse whole array
    reverse(a, 0, n-1);
    // 2. Reverse first k elements
    reverse(a, 0, k-1);
    // 3. Reverse remaining n-k elements
    reverse(a, k, n-1);

    // Print rotated array
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
