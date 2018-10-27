#include <iostream>
using namespace std;

int cifraMinima(int n) {
    if (n < 10) {
        return n;
    }
    return min(n % 10, cifraMinima(n / 10));
}

int cifraMaximaPara(int n) {
    if (n < 10) {
        return (n % 2 == 0) ? n : -1;
    }
    return max((n % 2 == 0) ? n % 10 : -1, cifraMaximaPara(n / 10));
}

int main() {
    int n = 0;
    cin >> n;
    cout << cifraMinima(n) << endl;
    cout << cifraMaximaPara(n);
    return 0;
}
