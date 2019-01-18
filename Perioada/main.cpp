#include <iostream>
using namespace std;

bool verif(int n, char x[], int perioada) {
    for (int i = perioada; i < n; i++) {
        if (x[i + 1] != x[i % perioada + 1]) {
            return false;
        }
    }
    return true;
}

int perioadaMax(int n, char x[]){
    int perioada = -1;
    for (int per = 2; per * per <= n; per++) {
        if (n % per == 0) {
            if (verif(n, x, n / per)) {
                return n / per;
            }
            if ((per * per < n) && verif(n, x, per)) {
                perioada = per;
                cout << "In third if\n";
            }
        }
    }
    return perioada;
}

int main() {
    cout << perioadaMax(8, "abababab");
    return 0;
}
