#include <iostream>
using namespace std;

struct Numar {
    int num = 0, forta = 0;

    void calcForta() {
        int n = num;
        int res = 0;
        while (n) {
            if (n & 1) {
                res++;
            }
            n >>= 1;
        }
        forta = res;
    }

    void schimba(Numar &n) {
        n.num ^= num;
        num ^= n.num;
        n.num ^= num;

        n.forta ^= forta;
        forta ^= n.forta;
        n.forta ^= forta;
    }
};

struct Grup {
    int n = 0, numere[120] = {0};
};

//Improve this sorting algorithm for better time than n^2
void sortDupaForta(int n, Numar X[]) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (X[i].forta > X[j].forta) {
            X[i].schimba(X[j]);
        }
    }
  }
}

void grupuriForta(int n, int x[], int &nrGr, Grup grupuri[]) {
    Numar X[n];
    grupuri = {0};
    for (int i = 0; i < n; i++) {
        X[i].num = x[i];
        X[i].calcForta();
    }
    /// sort by force
    sortDupaForta(n, X);
    for (int i = 0; i < n; i++) {
        cout << i << ". Numarul " << X[i].num << " cu forta " << X[i].forta << "\n";
    }
    /// check where force is different and split
    /*
    int prev = -1;
    int iGrup = 0;
    for (int i = 0; i < n; i++) {
        if (prev == -1) {
            grupuri[iGrup].numere[grupuri[iGrup].n++] = X[i].num;
            prev = X[i].forta;
            continue;
        }
        if (prev != X[i].forta) {
            grupuri[++iGrup].numere[grupuri[iGrup].n++] = X[i].num;
            prev = X[i].forta;
        } else {
            grupuri[iGrup].numere[grupuri[iGrup].n++] = X[i].num;
        }
    }
    nrGr = ++iGrup;
    */
}

int main() {
    int n = 0, x[120] = {0}, nrGr = 0;
    Grup grupuri[120];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    grupuriForta(n, x, nrGr, grupuri);
    for(int i = 0; i < nrGr; i++) {
        cout << "(";
        for (int j = 0; j < grupuri[i].n; j++) {
            cout << grupuri[i].numere[j];
            if (j < grupuri[i].n - 1) {
                cout << ", ";
            }
        }
        cout << ")";
        if (i < n - 1) {
            cout << ", ";
        }
    }
    return 0;
}
