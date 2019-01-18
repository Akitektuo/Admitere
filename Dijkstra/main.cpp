#include <iostream>
using namespace std;

int minDistance(int n, int dist[], bool sptSet[]) {
   int minVal = 100000, minIndex;
   for (int i = 0; i < n; i++) {
     if (!sptSet[i] && dist[i] <= minVal) {
         minVal = dist[i];
         minIndex = i;
     }
   }
   return minIndex;
}

void readGraph(int& n, int& s, int graph[101][101]) {
    int m = 0;
    cout << "Nodes - Paths - Starting node\n";
    cin >> n >> m >> s;
    for (int path = 0; path < m; path++) {
        int i = 0, j = 0, val = 0;
        cin >> i >> j >> val;
        graph[i][j] = val;
        graph[j][i] = val;
    }
}

void printSolution(int dist[], int n) {
    for (int i = 0; i < n; i++) {
        if (dist[i] == 100000) {
            dist[i] = -1;
        }
        cout << dist[i] << " ";
    }
}

void dijkstra(int graph[101][101], int n, int src) {
    int dist[n];
    bool sptSet[n];
    for (int i = 0; i < n; i++) {
       dist[i] = 100000;
       sptSet[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = minDistance(n, dist, sptSet);
        sptSet[minIndex] = true;
        for (int j = 0; j < n; j++) {
            if (!sptSet[j] && graph[minIndex][j] && dist[minIndex] != 100000 && dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }
    printSolution(dist, n);
}

int main() {
    int n = 0, s = 0;
    int graph[101][101];/* = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };*/
    readGraph(n, s, graph);
    dijkstra(graph, n, s);
    return 0;
}
