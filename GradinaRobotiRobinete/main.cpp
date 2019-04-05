#include <iostream>
using namespace std;

int robiGradina(int n, int t, int d[], int u[]) {
    int maxi = 1, app[20000] = {0};
    for (int i = 1; i <= n; i++) {
        int q = 2 * d[i] + u[i] + 1;
        for (int j = q; j <= t; j += q) {
            app[j]++;
            if(app[j] > maxi) {
                maxi = app[j];
            }
        }
    }
    return maxi - 1;
}

int main() {
    int n = 0, t = 0, d[101] = {0}, u[101] = {0};
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> u[i];
    }
    cout << robiGradina(n, t, d, u);
    return 0;
}
