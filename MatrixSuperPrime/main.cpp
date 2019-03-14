#include <iostream>
using namespace std;

struct Matrix
{
    int length = 0, elements[51][51];

    void read()
    {
        cin >> length;
        for (int i = 1; i <= length; i++)
        {
            for (int j = 1; j <= length; j++)
            {
                cin >> elements[i][j];
            }
        }
    }

    int get(int line, int column)
    {
        return elements[line][column];
    }

};

struct Array
{
    int length = 0, elements[2000] = {0};

    void print()
    {
        for (int i = 1; i <= length; i++)
        {
            cout << elements[i] << " ";
        }
    }

    bool contains(int value)
    {
        int left = 1, right = length, middle = 0;
        while (left < right) {
            middle = (right - left) / 2 + 1;
            if (elements[middle] == value)
            {
                return true;
            }
            if (elements[middle] < value)
            {
                right = middle - 1;
                continue;
            }
            left = middle + 1;
        }
        return elements[left] == value;
    }

    void add(int value)
    {
        if (contains(value))
        {
            return;
        }
        if (length < 1 || elements[length] > value)
        {
            elements[++length] = value;
            return;
        }
        elements[0] = 100000;
        int i = length + 1;
        while (i > 1) {
            elements[i] = elements[i - 1];
            if (value < elements[i - 2])
            {
                elements[i - 1] = value;
                length++;
                break;
            }
            i--;
        }
        elements[0] = 0;
    }
};

bool isPrime(int number)
{
    if (number < 2) {
        return false;
    }
    if (number < 4) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= number; i += 6)
    {
        if (number % i == 0 || number % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

bool isSuperPrime(int number)
{
    while (number > 0)
    {
        if (!isPrime(number))
        {
            return false;
        }
        number /= 10;
    }
    return true;
}

int main()
{
    Matrix matrix;
    Array arr;

    matrix.read();

    for (int i = 1; i <= matrix.length; i++)
    {
        for (int j = 1; j <= matrix.length; j++)
        {
            if ((i > j && i < matrix.length - j + 1) || (i < j && i > matrix.length - j + 1))
            {
                int element = matrix.get(i, j);
                if (isSuperPrime(element))
                {
                    arr.add(element);
                }
            }
        }
    }

    arr.print();
    return 0;
}
