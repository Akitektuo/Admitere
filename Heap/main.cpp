#include <iostream>
using namespace std;

struct Heap {
    int nodes[100000] = { 0 };
    int length = 0;

    void swapVals(int& valA, int& valB) {
        valA ^= valB;
        valB ^= valA;
        valA ^= valB;
    }

    void checkParent(int index) {
        if (index < 1) {
            return;
        }
        int parentIndex = (index - 1) / 2;
        if (nodes[parentIndex] > nodes[index]) {
            swapVals(nodes[parentIndex], nodes[index]);
            checkParent(parentIndex);
        }
    }

    void add(int val) {
        int index = length++;
        nodes[index] = val;
        if (index > 0) {
            checkParent(index);
        }
    }

    bool isNodeInOrder(int index) {
        int leftChildIndex = 2 * index + 1,
            rightChildIndex = 2 * index + 2;
        if (leftChildIndex >= length) {
            return true;
        }
        bool cond = nodes[index] < nodes[leftChildIndex];
        if (rightChildIndex < length) {
            cond = cond && nodes[index] < nodes[rightChildIndex];
        }
        return cond;
    }

    int getMinValueIndex(int index) {
        int leftChildIndex = 2 * index + 1,
            rightChildIndex = 2 * index + 2;
        if (nodes[leftChildIndex] > nodes[rightChildIndex]) {
            return rightChildIndex;
        }
        return leftChildIndex;
    }

    void checkNode(int parentIndex) {
        if (isNodeInOrder(parentIndex)) {
            return;
        }
        int minIndex = getMinValueIndex(parentIndex);
        swapVals(nodes[parentIndex], nodes[minIndex]);
        checkNode(minIndex);
    }

    int pop() {
        if (length < 1) {
            return -1;
        }
        int val = nodes[0];
        nodes[0] = nodes[--length];
        checkNode(0);
        return val;
    }

    void print() {
        if (length < 1) {
            cout << "Heap is empty...\n";
            return;
        }
        for (int i = 0; i < length; i++) {
            cout << i << ": " << nodes[i] << "\n";
        }
    }

};

void addValue(Heap& heap) {
    cout << "Enter a value\n";
    int val = 0;
    cin >> val;
    heap.add(val);
    cout << "\n";
}

void popValue(Heap& heap) {
    int val = heap.pop();
    if (val < 0) {
        cout << "Heap is empty...\n\n";
        return;
    }
    cout << "The parent was " << val << "\n\n";
}

void print(Heap heap) {
    heap.print();
    cout << "\n";
}

void showError() {
    cout << "Invalid input, redirecting...\n\n";
}

void showMenu(Heap& heap) {
    cout << "Menu\n1: add a value\n2: pop a value\n3: print heap\n";
    int option = 0;
    cin >> option;
    cout << "\n";
    switch (option) {
        case 1:
            addValue(heap);
            break;
        case 2:
            popValue(heap);
            break;
        case 3:
            print(heap);
            break;
        default:
            showError();
    }
}

int main() {
    Heap heap;
    cout << "Running...\n";
    while(true) {
        showMenu(heap);
    }
    return 0;
}
