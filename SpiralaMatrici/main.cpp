#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int nextPrime(int n) {
    while (isPrime(++n));
    return n;
}

void citireDimensiuni(int& n, int& m) {
    cin >> n >> m;
}

// fix this, does not work
void completareMatrice(int n, int m, int mat[101][101]) {
    int r = min(n, m);
    int prim = 2;
    for (int i = 0; i < r / 2 + r % 2; i++) {
        for (int j = i; j < m - i; j++) {
            mat[i][j] = prim;
            prim = nextPrime(prim);
        }
        for (int j = i + 1; j < n - i; j++) {
            mat[j][m - i - 1] = prim;
            prim = nextPrime(prim);
        }
        for (int j = m - i - 2; j >= i; j--) {
            mat[n - i - 1][j] = prim;
            prim = nextPrime(prim);
        }
        for (int j = n - i - 2; j > i; j--) {
            mat[j][i] = prim;
            prim = nextPrime(prim);
        }
    }
}

void afisareMatrice(int n, int m, int mat[101][101]) {
    for (int i  = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 0, m = 0, mat[101][101];
    citireDimensiuni(n, m);
    completareMatrice(n, m, mat);
    afisareMatrice(n, m, mat);
    return 0;
}
