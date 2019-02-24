#include <iostream>
using namespace std;

int log2(int n) {
    if (n == 1) {
        return 0;
    }
    return 1 + log2(n / 2);
}

int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h) {
    if (depth == h) {
        return scores[nodeIndex];
    }
    if (isMax) {
        return max(minimax(depth + 1, nodeIndex * 2, false, scores, h), minimax(depth + 1, nodeIndex * 2 + 1, false, scores, h));
    }
    return min(minimax(depth + 1, nodeIndex * 2, true, scores, h), minimax(depth + 1, nodeIndex * 2 + 1, true, scores, h));
}

int main() {
    int n = 0, scores[128] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    cout << minimax(0, 0, true, scores, log2(n));
    return 0;
}
