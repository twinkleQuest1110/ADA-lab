#include <iostream>
using namespace std;

#define INF 9999

int main()
{
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[20][20];

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    int dist[20];
    bool visited[20];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int min = INF, u;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << source << " -> " << i << " = " << dist[i] << endl;
    }

    return 0;
}