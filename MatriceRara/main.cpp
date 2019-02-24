#include <iostream>
using namespace std;

int n = 0, m = 0;

struct Item
{
    int l = 0, c = 0, v = 0;

    Item() {}

    Item(int linie, int coloana, int valoare)
    {
        l = linie;
        c = coloana;
        v = valoare;
    }

    void readValues()
    {
        cin >> l >> c >> v;
    }

    bool isValid()
    {
        return !(l == c && c == v && c == -1);
    }
};

bool maiMicaLexicografic(Item i1, Item i2)
{
    return i1.l < i2.l || (i1.l == i2.l && i1.c < i2.c);
}

struct Mat
{
    Item vals[100];
    int length = 0;

    void add(Item item)
    {
        if (!item.isValid())
        {
            return;
        }
        if (length < 1)
        {
            vals[length++] = item;
            return;
        }

        int i = length;
        while (i > 0 && maiMicaLexicografic(item, vals[i - 1]))
        {
            vals[i] = vals[i - 1];
            i--;
        }
        vals[i] = item;
        length++;
    }

    void citeste()
    {
        Item item;
        do
        {
            item.readValues();
            add(item);
        }
        while (item.isValid());
    }

    Item findVal(int l, int c)
    {
        Item item = Item(l, c, 0);
        int s = 0, e = length - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (vals[m].l == l && vals[m].c == c)
            {
                return vals[m];
            }
            if (maiMicaLexicografic(vals[m], item))
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        return item;
    }

    void afiseaza()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << findVal(i, j).v << " ";
            }
            cout << "\n";
        }
    }

};

void citesteMatrici(Mat& A, Mat& B)
{
    cin >> n >> m;
    A.citeste();
    B.citeste();
}

Mat aduna(Mat A, Mat B)
{
    Mat C;
    int i = 0, j = 0;
    while (i < A.length && j < B.length)
    {
        if (maiMicaLexicografic(A.vals[i], B.vals[j]))
        {
            C.add(A.vals[i++]);
            continue;
        }
        if (maiMicaLexicografic(B.vals[j], A.vals[i]))
        {
            C.add(B.vals[j++]);
            continue;
        }
        Item item = A.vals[i++];
        item.v += B.vals[j++].v;
        if (item.v != 0)
        {
            C.add(item);
        }
    }
    while (i < A.length)
    {
        C.add(A.vals[i++]);
    }
    while (j < B.length)
    {
        C.add(B.vals[j++]);
    }
    return C;
}

int main()
{
    Mat A, B;
    citesteMatrici(A, B);
    aduna(A, B).afiseaza();
    return 0;
}
