#include <iostream>
using namespace std;

int nrCifre(int n) {
    int res = 0;
    while (n) {
        res++;
        n /= 10;
    }
    return res;
}

void transformareInSir(int nr, int &n, int N[]) {
    n = nrCifre(nr);
    for (int i = 1; i <= n; i++) {
        int c  = nr % 10;
        N[n - i + 1] = c;
        nr /= 10;
    }
}

int transformareInNr(int n, int N[]) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = res * 10 + N[i];
    }
    return res;
}

void eliminare(int indice, int &n, int N[]) {
    for (int i = indice; i < n; i++) {
        N[i] = N[i + 1];
    }
    n--;
}

void taiere(int &n, int N[]) {
    bool cut = 0;
    for (int i = 1; i < n && !cut; i++) {
        if (i + 1 == n) {
            if (N[i] < N[i + 1]) {
                N[i] = N[i + 1];
            }
            n--;
            cut = 1;
        } else {
            if (N[i] < N[i + 1]) {
                eliminare(i, n, N);
                cut = 1;
            }
        }
    }
}

int taiereK(int n, int N[], int k) {
    for (int i = 1; i <= k; i++) {
        taiere(n, N);
        cout << "k=" << i << " => n=" << transformareInNr(n, N) << "\n";
    }
    return transformareInNr(n, N);
}


int main() {
    int nr = 0, k = 0, N[101] = {0}, n;
    while (1) {
        cin >> nr >> k;
        transformareInSir(nr, n, N);
        taiereK(n, N, k);
        cout << "\n";
    }
    return 0;
}
