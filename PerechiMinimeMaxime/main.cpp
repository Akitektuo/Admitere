#include <iostream>
using namespace std;

int numarPerechi(int k) {
    return k * (k - 1) / 2;
}

int numarMaximPerechi(int n, int m) {
    return numarPerechi(n - m + 1);
}

int numarMinimPerechi(int n, int m) {
    int nrMinimMembri = n / m;
    int membriRamasi = n % m;
    return membriRamasi * numarPerechi(nrMinimMembri + 1) + (m - membriRamasi) * numarPerechi(nrMinimMembri);
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    cout << numarMinimPerechi(n, m) << " " << numarMaximPerechi(n, m);
    return 0;
}
