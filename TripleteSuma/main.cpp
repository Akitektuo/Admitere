#include <iostream>
using namespace std;

struct Triplet {
    int x, y, z;
};

void citesteSir(int &n, int sir[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sir[i];
    }
}

void afiseazaSir(int n, int sir[]){
    for (int i = 0; i < n; i++) {
        cout << sir[i] << " ";
    }
    cout<<endl;
}

void sortSir(int n, int sir[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sir[i] > sir[j]) {
                sir[i] ^= sir[j];
                sir[j] ^= sir[i];
                sir[i] ^= sir[j];
            }
        }
    }
}

void mergeSir(int sir[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = sir[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = sir[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            sir[k++] = L[i++];
        } else {
            sir[k++] = R[j++];
        }
    }
    while (i < n1) {
        sir[k++] = L[i++];
    }
    while (j < n2) {
        sir[k++] = R[j++];
    }
}

void mergeSort(int sir[], int l, int r) {
    if (l < r) {
        int m = (l+r) / 2;
        mergeSort(sir, l, m);
        mergeSort(sir, m+1, r);
        mergeSir(sir, l, m, r);
    }
}

int binarySearch(int sir[], int l, int r, int x) {
    if (l <= r) {
        int m = (l + r) / 2;
        if (sir[m] == x) {
            return m;
        }
        if (sir[m] > x) {
            return binarySearch(sir, l, m - 1, x);
        } else {
            return binarySearch(sir, m + 1, r, x);
        }
    }
    return -1;
}

void afiseazaTriplet(int n, Triplet trip[]) {
    for (int i = 0; i < n; i++) {
        cout << trip[i].x << " " << trip[i].y << " " << trip[i].z << "\n";
    }
}

int main()
{
    int n, s, sir[500];
    Triplet trip[500];
    citesteSir(n, sir);
    mergeSort(sir, 0, n - 1);
    cin >> s;
    int l = 0;
    for (int a = 0; a < n; a++) {
        if (sir[a] >= s) {
            break;
        }
        int b = a + 1;
        int c = n - 1;
        while (b < c) {
            int sum = sir[a] + sir[b] + sir[c];
            if (sum == s) {
                trip[l].x = sir[a];
                trip[l].y = sir[b];
                trip[l].z = sir[c];
                l++;
                b++;
            } else if (sum > s) {
                c--;
            } else {
                b++;
            }
        }
    }
    afiseazaTriplet(l, trip);
    return 0;
}
