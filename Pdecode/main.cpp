#include <iostream>
using namespace std;

struct Permutare {
    int ordin = 0, sir[100] = {0};

    Permutare inversare() {
        Permutare rez;
        rez.ordin = ordin;
        for (int i = 1; i <= ordin; i++) {
            rez.sir[sir[i]] = i;
        }
        return rez;
    }

    Permutare compunereCu(Permutare p) {
        Permutare rez;
        rez.ordin = ordin;
        for (int i = 1; i <= ordin; i++) {
            rez.sir[i] = sir[p.sir[i]];
        }
        return rez;
    }
};

Permutare putere(Permutare p, int n) {
    Permutare rez;
    rez.ordin = p.ordin;
    for (int i = 1; i < p.ordin; i++) {
        rez.sir[i] = i;
    }
    while (n > 0) {
        if (n % 2 == 0) {
            p = p.compunereCu(p);
            n /= 2;
        } else {
            n--;
            rez = rez.compunereCu(p);
        }
    }
    return rez;
}

int main() {
    Permutare p;
    int n = 0, m = 0;
    char F[100], T[100];
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        p.ordin = n;
        for (int i = 1; i <= n; i++) {
            cin >> p.sir[i];
        }
        cin.getline(F + 1, 100);
        cin.getline(F + 1, 100);
        p = p.inversare();
        p = putere(p, m);
        for (int i = 1; i <= n; i++) {
            T[i] = F[p.sir[i]];
        }
        T[n + 1] = '\0';
        cout << T + 1 << "\n";
    }
    return 0;
}
