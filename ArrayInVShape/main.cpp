#include <iostream>
using namespace std;

bool isV(int n, int arr[]) {
    if (n < 2) {
        return false;
    }
    if (arr[0] < arr[1] || arr[n - 2] > arr[n - 1]) {
        return false;
    }
    bool switched = false;
    for (int i = 1; i < n; i++) {
        //cout << arr[i - 1] << " " << arr[i] << " " << switched << "\n";
        if (arr[i - 1] > arr[i] && switched) {
            return false;
        }
        if (arr[i - 1] <= arr[i]) {
            switched = true;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Sirul " << (isV(n, arr) ? "" : "nu ") << "are forma de V.";
    return 0;
}
