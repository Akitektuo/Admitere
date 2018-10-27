#include <iostream>
using namespace std;

int cifraMinima(int n) {
    if (n < 10) {
        return n;
    }
    return min(n % 10, cifraMinima(n / 10));
}

int cifraMinimaIterativ(int n) {
    while (n > 9) {
        n = (n / 100) * 10 + min(n % 10, (n / 10) % 10);
    }
    return n;
}

int cifraMaximaPara(int n) {
    if (n < 10) {
        return n % 2 == 0 ? n : -1;
    }
    return max(n % 2 == 0 ? n % 10 : -1, cifraMaximaPara(n / 10));
}

int main() {
    int n = 0;
    cin >> n;
    cout << cifraMinimaIterativ(n) << endl;
    cout << cifraMaximaPara(n);
    return 0;
}
