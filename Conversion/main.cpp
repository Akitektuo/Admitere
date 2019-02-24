#include <iostream>
using namespace std;

int convertIterative(char s[], int length)
{
    int num = 0;
    for (int i = 1; i <= length; i++)
    {
        if (s[i] >= 'A')
        {
            num = num * 16 + s[i] - 'A' + 10;
        }
        else
        {
            num = num * 16 + s[i] - '0';
        }
    }
    return num;
}

int convertRecursive(char s[], int length)
{
    if (length < 1)
    {
        return 0;
    }
    if (s[length] >= 'A')
    {
        return convertRecursive(s, length - 1) * 16 + s[length] - 'A' + 10;
    }
    return convertRecursive(s, length - 1) * 16 + s[length] - '0';
}

int main()
{
    cout << convertIterative(" DEF123", 6) << "\n";
    cout << convertRecursive(" DEF123", 6);
    return 0;
}
