#include <iostream>
using namespace std;

int cutRodRec(int n, int prices[]) {
    if (n < 1) {
        return 0;
    }
    int maxPrice = 0;
    for (int i = 1; i <= n; i++) {
        maxPrice = max(maxPrice, prices[i] + cutRodRec(n - i, prices));
    }
    return maxPrice;
}

int cutRodDin(int n, int prices[]) {
    int val[n + 1];
    val[0] = 0;
    for (int i = 1; i <= n; i++) {
        int maxVal = 0;
        for (int j = 1; j <= i; j++) {
            maxVal = max(maxVal, prices[j] + val[i - j]);
        }
        val[i] = maxVal;
    }
    return val[n];
}

int main() {
    int n;
    cin >> n;
    int prices[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
    cout << cutRodDin(n, prices);
    return 0;
}
