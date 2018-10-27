#include <iostream>
using namespace std;

int cmmmc(int a, int b) {
    if (b > a) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int rez = a;
    while (rez % b != 0) {
        rez += a;
    }
    return rez;
}

void circuite(int n, int& c1, int& c2, int& c3) {
    int l1 = 4 * (n - 1);
    int l2 = 4 * (n - 3);
    int l3 = 4 * (n - 5);

    int intalnire = cmmmc(cmmmc(l1, l2), l3);

    c1 = intalnire / l1;
    c2 = intalnire / l2;
    c3 = intalnire / l3;
}

int main() {
    int n = 0, c1 = 0, c2 = 0, c3 = 0;
    cin >> n;
    circuite(n, c1, c2, c3);
    cout << c1 << " " << c2 << " " << c3;
    return 0;
}
