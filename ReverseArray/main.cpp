#include <iostream>
using namespace std;

struct Word {
    char c[256];
};

void reverseArray(char arr[], int st, int sf) {
    while (st < sf) {
        arr[st] ^= arr[sf];
        arr[sf] ^= arr[st];
        arr[st++] ^= arr[sf--];
    }
}

string reverseWords(string str)
{
    int i = str.length() - 1;
    int start, end = i + 1;
    string result = "";
    while(i >= 0) {
        if(str[i] == ' ') {
            start = i + 1;
            while(start != end)
                result += str[start++];

            result += ' ';

            end = i;
        }
        i--;
    }
    start = 0;
    while(start != end)
        result += str[start++];

    return result;
}

int main() {
    string str;
    getline(cin, str);
    cout << reverseWords(str);
    return 0;
}
