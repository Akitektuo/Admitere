#include <iostream>
using namespace std;

int power(int x, int n) {
    int res;
    if (n == 0) {
        return 1;
    }
    res = power(x, n / 2);
    if (n % 2 == 0) {
        return res * res;
    }
    return x * res * res;
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << power(x, n);
    return 0;
}
