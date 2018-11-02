#include <iostream>
using namespace std;

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

bool hasDuplicates(int n, int arr[]) {
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Sirul " << (hasDuplicates(n, arr) ? "" : "nu ") << "are duplicate.";
    return 0;
}
