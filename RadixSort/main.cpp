#include <iostream>
using namespace std;

int getMax(int n, int nums[]) {
    int maxNum = 0;
    for (int i = 1; i <= n; i++) {
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }
    return maxNum;
}

int getLastDigit(int n) {
    return n % 10;
}

void countSort(int n, int nums[], int digit) {
    int app[10] = { 0 }, output[n + 1];
    for (int i = 1; i <= n; i++) {
        app[getLastDigit(nums[i] / digit)]++;
    }
    for (int i = 1; i < 10; i++) {
        app[i] += app[i - 1];
    }
    for (int i = n; i > 0; i--) {
        int lastDigit = getLastDigit(nums[i] / digit);
        output[app[lastDigit]] = nums[i];
        app[lastDigit]--;
    }
    for (int i = 1; i <= n; i++) {
        nums[i] = output[i];
    }
}

void radixSort(int n, int nums[]) {
    int maxNum = getMax(n, nums);
    for (int i = 1; maxNum / i > 0; i *= 10) {
        countSort(n, nums, i);
    }
}

int getNumberOfBits(int n) {
    int bits = 0;
    while (n) {
        n >>= 1;
        bits++;
    }
    return bits;
}

void bucketSort(int n, int nums[], int digit) {
     int arr[2][n + 1], length0 = 0, length1 = 0;
     for (int i = 1; i <= n; i++) {
        if ((nums[i] >> digit) & 1) {
            arr[1][length1++] = nums[i];
        } else {
            arr[0][length0++] = nums[i];
        }
     }
     int i = 1;
     for (int j = 0; j < length0; j++) {
        nums[i++] = arr[0][j];
     }
     for (int j = 0; j < length1; j++) {
        nums[i++] = arr[1][j];
     }
}

void radixSortBit(int n, int nums[]) {
    int digits = getNumberOfBits(getMax(n, nums));
    for (int i = 0; i < digits; i++) {
        bucketSort(n, nums, i);
    }
}

int main() {
    int n;
    while(1) {
        cin >> n;
        int nums[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }

        radixSortBit(n, nums);

        for (int i = 1; i <= n; i++) {
            cout << nums[i] << " ";
        }
    }
    return 0;
}
