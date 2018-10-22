#include <iostream>
using namespace std;

void ciurulLuiEratosthenes(int n)
{
    bool prime[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = 1;
    }
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i= p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
       if (prime[p]) {
          cout << p << " ";
       }
    }
}

int main()
{
    int n;
    cin >> n;
    ciurulLuiEratosthenes(n);
    return 0;
}
