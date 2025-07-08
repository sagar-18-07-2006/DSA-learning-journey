#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    int n;
    cin >> n;
    int sum = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Sum: " << sum << "\n";
    cout << "Time taken: " << duration.count() << " ms\n";

    return 0;
}
