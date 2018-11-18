#include <iostream>
using namespace std;

int cautare(int ci[], int n, int c) {
    int rez = 0;
    for (int i = 1; i <= n && rez == 0; i++) {
        if (ci[i] == c) {
            rez = i;
        }
    }
    return rez;
}

int nepotrivire(int ci[], int cf[], int n) {
    int rez = 0;
    for (int i = 1; i <= n && rez == 0; i++) {
        if (ci[i] != cf[i]) {
            rez = i;
        }
    }
    return rez;
}

void mutari(int ci[], int cf[], int m, int& n, int res[][]) {
    int i = 1;
    int np = nepotrivire(ci, cf, m);
    while (np != 0) {
        if (ci[np] != 0) {
            int po = cautare(ci, m, 0);
            ci[np] ^= ci[po];
            ci[po] ^= ci[np];
            ci[np] ^= ci[po];
            int pp = cautare(ci, m, cf[np])
        }
    }
}

int main() {
    cout << "Hello world!" << endl;
    return 0;
}
