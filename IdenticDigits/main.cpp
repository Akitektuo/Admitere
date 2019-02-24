#include <iostream>
using namespace std;

int getNumOfDigits(int num)
{
    int res = 0;
    while (num > 0)
    {
        num /= 10;
        res++;
    }
    return res;
}

void computeIdenticalDigits(int a, int b, int& k, int x[])
{
    int digitsStart = getNumOfDigits(a);
    int digitsEnd = getNumOfDigits(b);
    k = 0;
    for (int i = digitsStart; i <= digitsEnd; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            x[k] = 0;
            for (int r = 0; r < i; r++)
            {
                x[k] = x[k] * 10 + j;
            }
            if (x[k] >= a && x[k] <= b)
            {
                k++;
            }
        }
    }
}

int main()
{
    int a = 0, b = 0, length = 0, x[1000] = {0};
    cin >> a >> b;
    computeIdenticalDigits(a, b, length, x);
    cout << length << "\n";
    for (int i = 0; i < length; i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}
