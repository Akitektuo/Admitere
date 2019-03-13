#include <iostream>
using namespace std;

struct Sequence
{
    int left = 0, right = 0;

    int getLength()
    {
        return right - left + 1;
    }

    bool isValid()
    {
        return getLength() > 1;
    }

    bool isUnset()
    {
        return left == right;
    }

    void reset()
    {
        left = right = 0;
    }

    void copyFrom(Sequence sequence)
    {
        left = sequence.left;
        right = sequence.right;
    }
};

struct Array
{
    int length = 0, elements[1001] = {0};

    void read()
    {
        cin >> length;
        for (int i = 1; i <= length; i++)
        {
            cin >> elements[i];
        }
    }

    void add(int value)
    {
        elements[++length] = value;
    }

    int get(int index)
    {
        return elements[index];
    }

    void addFirst(int value)
    {
        if (length < 1)
        {
            add(value);
            return;
        }
        for (int i = length; i > 0; i--)
        {
            elements[i + 1] = elements[i];
        }
        elements[1] = value;
        length++;
    }

    void print(Sequence sequence)
    {
        if (!sequence.isValid())
        {
            cout << "Secventa este vida";
            return;
        }
        for (int i = sequence.left; i <= sequence.right; i++)
        {
            cout << get(i) << " ";
        }
    }
};

Array getDigits(int number)
{
    Array digits;
    if (number == 0)
    {
        digits.add(0);
        return digits;
    }
    digits.length = 0;
    while(number > 0)
    {
        digits.addFirst(number % 10);
        number /= 10;
    }
    return digits;
}

bool isPrefix(int currentNumber, int nextNumber)
{
    Array currentDigits = getDigits(currentNumber);
    Array nextDigits = getDigits(nextNumber);
    if (currentDigits.length >= nextDigits.length)
    {
        return false;
    }
    for (int i = 1; i <= currentDigits.length; i++)
    {
        if (currentDigits.get(i) != nextDigits.get(i))
        {
            return false;
        }
    }
    return true;
}

Sequence getSequence(Array arr)
{
    Sequence sequence, maxSequence;
    for (int i = 1; i < arr.length; i++)
    {
        if (sequence.isUnset())
        {
            sequence.left = i;
        }
        if (isPrefix(arr.get(i), arr.get(i + 1)))
        {
            sequence.right = i + 1;
            if (sequence.getLength() > maxSequence.getLength())
            {
                maxSequence.copyFrom(sequence);
            }
            continue;
        }
        sequence.reset();
    }
    return maxSequence;
}

int main()
{
    Array arr;
    arr.read();
    Sequence sequence = getSequence(arr);
    arr.print(sequence);
    return 0;
}
