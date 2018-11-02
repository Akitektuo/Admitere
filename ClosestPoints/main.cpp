#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Punct {
    int x = 0, y = 0;
    void copyTo(Punct &to) {
        to.x = x;
        to.y = y;
    }
};

float squareRoot(int number)
{
    int start = 0, end = number, mid;
    float res;
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            res = mid;
            break;
        }
        if (mid * mid < number) {
            start = mid + 1;
            res = mid;
        }
        else {
            end = mid - 1;
        }
    }
    float increment = 0.1;
    for (int i = 0; i < 4; i++) {
        while (res * res <= number) {
            res += increment;
        }
        res -= increment;
        increment /= 10;
    }
    return res;
}

float distPuncte(Punct p1, Punct p2) {
	return squareRoot((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int findPointsBasic(int n, Punct P[]) {
    int minL = 10000000;
    Punct resPa, resPb;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = distPuncte(P[i], P[j]);
            int init = minL;
            minL = min(minL, dist);
            if (minL < init) {
                P[i].copyTo(resPa);
                P[j].copyTo(resPb);
            }
        }
    }
    cout << "\n(" << resPa.x << ", " << resPa.y << ") si (" << resPb.x << ", " << resPb.y << ") au distanta patrata " << minL << endl;
}

int compareX(const void* a, const void* b) {
    Punct *p1 = (Punct *)a,  *p2 = (Punct *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
    Punct *p1 = (Punct *)a,   *p2 = (Punct *)b;
    return (p1->y - p2->y);
}

float dist(Punct p1, Punct p2) {
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

float bruteForce(Punct P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float min(float x, float y) {
    return (x < y)? x : y;
}

float stripClosest(Punct strip[], int size, float d) {
    float min = d;
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float closestUtil(Punct Px[], Punct Py[], int n) {
    if (n <= 3)
        return bruteForce(Px, n);
    int mid = n/2;
    Punct midPoint = Px[mid];
    Punct Pyl[mid+1];
    Punct Pyr[n-mid-1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
    float d = min(dl, dr);
    Punct strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
    return min(d, stripClosest(strip, j, d) );
}

float closest(Punct P[], int n) {
    Punct Px[n];
    Punct Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Punct), compareX);
    qsort(Py, n, sizeof(Punct), compareY);
    return closestUtil(Px, Py, n);
}

int main() {
    int n;
    cin >> n;
    Punct P[n];
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    findPointsBasic(n, P);
    cout << closest(P, n);
    return 0;
}
