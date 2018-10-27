#include <iostream>
using namespace std;

// (a * b) % c = ((a % c) * (b % c)) % c
int rest(int base, int power, int divisor) {
    if (power == 0) {
        return 1;
    }
    return ((base % divisor) * (rest(base, power - 1, divisor) % divisor)) % divisor;
}

int main() {
    int i = 0, j = 0, k = 0;
    cin >> i >> j >> k;
    cout << rest(i, j, k);
    return 0;
}
