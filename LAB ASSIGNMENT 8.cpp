#include <iostream>
using namespace std;

const int N = 5;
const int INF = 1e9;

void dijkstra(int graph[N][N], int source, int distances[]) {
    bool visited[N] = {false};
    
    for (int i = 0; i < N; ++i) {
        distances[i] = INF;
    }
    distances[source] = 0;

    for (int i = 0; i < N - 1; ++i) {
        int minDist = INF, u = -1;

        for (int j = 0; j < N; ++j) {
            if (!visited[j] && distances[j] < minDist) {
                minDist = distances[j];
                u = j;
            }
        }

        if (u == -1) break;  // No reachable node left
        
        visited[u] = true;

        for (int v = 0; v < N; ++v) {
            if (!visited[v] && graph[u][v] && distances[u] != INF &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int graph[N][N] = {
        {0, 10, 3, 0, 0},
        {0, 0, 1, 2, 0},
        {0, 4, 0, 8, 2},
        {0, 0, 0, 0, 7},
        {0, 0, 0, 9, 0}
    };

    int source = 0;
    int distances[N];
    dijkstra(graph, source, distances);

    cout << "Shortest paths from landmark " << source << ":\n";
    for (int i = 0; i < N; ++i) {
        cout << "To landmark " << i << ": " << distances[i] << endl;
    }

    return 0;
}

