#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of Rows: ";
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;

            int val = n - min({top, left, right, bottom});
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
