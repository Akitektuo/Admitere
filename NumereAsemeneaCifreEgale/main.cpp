#include <iostream>
using namespace std;

bool cifreAinB(int a, int b) {
    int copieB = b;
    while (a > 0) {
        int ultimaCifraA = a % 10;
        while (copieB > 0 && ultimaCifraA != copieB % 10) {
            copieB /= 10;
        }
        if (0 == copieB) {
            return false;
        }
        copieB = b;
        a /= 10;
    }
    return true;
}

bool cifreAsemanatoare(int a, int b) {
    return cifreAinB(a, b) && cifreAinB(b, a);
}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    cout << (cifreAsemanatoare(a, b) ? "Asemenea" : "Neasemenea");
    return 0;
}
