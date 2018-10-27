#include <iostream>
using namespace std;

struct Punct {
    int x = 0, y = 0;
    void copyTo(Punct &to) {
        to.x = x;
        to.y = y;
    }
};

int distPuncte(Punct a, Punct b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int findPointsBasic(int n, Punct P[]) {
    int minL = 10000000;
    Punct resPa, resPb;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = distPuncte(P[i], P[j]);
            int init = minL;
            minL = min(minL, dist);
            if (minL < init) {
                P[i].copyTo(resPa);
                P[j].copyTo(resPb);
            }
        }
    }
    cout << "\n(" << resPa.x << ", " << resPa.y << ") si (" << resPb.x << ", " << resPb.y << ") au distanta patrata " << minL;
}

void mergeArr(int arr[], int l, int m, int r)
{
    int i = 0, j = 0, k = l;
    int n1 = m - l + 1, n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeArr(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    Punct P[n];
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    findPointsBasic(n, P);
    return 0;
}
