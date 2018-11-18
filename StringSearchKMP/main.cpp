#include <iostream>
using namespace std;

void readSentenceAndWord(char sentence[], char word[]) {
    cin.getline(sentence, 512);
    cin.getline(word, 216);
}

int getLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int searchOccurances(char sentence[], char word[], int res[]) {
    int sentenceLength = getLength(sentence), wordLength = getLength(word), length = 0;
    int j = 0;
    cout << "Lengths: " << sentenceLength << " & " << wordLength << "\n\n";
    for (int i = 0; i < sentenceLength; i++) {
        cout << "S: i=" << i << " v=" << sentence[i] << "\nW: i=" << j << " v=" << word[j] << "\n\n";
        if (sentence[i] == word[j]) {
            j++;
            if (j == wordLength) {
                j = 0;
                res[++length] = i - wordLength + 1;
            }
        } else {
            j = 0;
        }
    }
    return length;
}

void outputPatterns(int length, int res[]) {
    cout << "\n";
    for (int i = 1; i <= length; i++) {
        cout << "Pattern found at index " << res[i] << "\n";
    }
}

void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt)
{
    int M = getLength(pat);
    int N = getLength(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            cout << "Found pattern at index " << i - j << "\n";
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char sentence[512], word[216];
    readSentenceAndWord(sentence, word);
    KMPSearch(word, sentence);
    return 0;
}
