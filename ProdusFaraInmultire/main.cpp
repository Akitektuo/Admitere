#include <iostream>
using namespace std;

void citesteSir(int& length, int nums[]) {
    cin >> length;
    for (int i = 1; i <= length; i++) {
        cin >> nums[i];
    }
}

void afiseazaSir(int length, int nums[]) {
    for (int i = 1; i <= length; i++) {
        cout << nums[i] << " ";
    }
}

int computeazaMultiplicari(int length, int nums[], int rez[]) {
    if (length < 2) {
        return 0;
    }
    if (length == 2) {
        rez[1] = nums[2];
        rez[2] = nums[1];
        return nums[1] * nums[2];
    }
    int prod = computeazaMultiplicari(length - 1, nums, rez);
    for (int i = 1; i <= length - 1; i++) {
        rez[i] *= nums[length];
    }
    rez[length] = prod;
    return prod * nums[length];
}

int main() {
    int n = 0, nums[10001] = {0}, rez[10001] = {0};
    citesteSir(n, nums);
    computeazaMultiplicari(n, nums, rez);
    afiseazaSir(n, rez);
    return 0;
}
