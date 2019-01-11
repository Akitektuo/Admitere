#include <iostream>
using namespace std;

struct ArrayList {
    int length = 0;
    int arr[101] = {0};

    void add(int num) {
        arr[length++] = num;
    }

    int get(int index) {
       return arr[index];
    }

    int getLength() {
        return length;
    }
};

int main() {
    ArrayList arr;

    return 0;
}
