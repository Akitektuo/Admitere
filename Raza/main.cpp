#include <iostream>
using namespace std;

int schimb(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int cmmdc(int a, int b) {
    if (a == 0) {
        return b;
    }
    return cmmdc(b % a, a);
}

int main() {
    int l = 0, L = 0;
    cin >> L >> l;
    if (l > L) {
        schimb(l, L);
    }
    cout << "\nL: " << L << "\nl: " << l << "\nCMMDC: " << cmmdc(l, L);
    int res = (l + L) / cmmdc(l, L) - 2;
    cout << "\n\nRezultat: " << res << "\n";
    return 0;
}
