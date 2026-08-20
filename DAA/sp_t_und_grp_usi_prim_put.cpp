#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

struct Edge
{
    int u, v, weight;
};

// ---------------- PRIM'S ALGORITHM ----------------
void prims(int graph[MAX][MAX], int n)
{
    int selected[MAX] = {0};
    int totalCost = 0;

    selected[0] = 1;

    cout << "\nMinimum Spanning Tree using Prim's Algorithm:\n";
    cout << "Edge\tCost\n";

    for (int count = 0; count < n - 1; count++)
    {
        int min = 9999;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] != 0)
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x + 1 << " - " << y + 1 << "\t" << min << endl;

        totalCost += min;
        selected[y] = 1;
    }

    cout << "Minimum Cost = " << totalCost << endl;
}

// ---------------- KRUSKAL'S ALGORITHM ----------------

int findParent(int parent[], int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    return findParent(parent, parent[vertex]);
}

void unionSet(int parent[], int u, int v)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    parent[rootU] = rootV;
}

void kruskals(int graph[MAX][MAX], int n)
{
    Edge edges[MAX * MAX];
    int edgeCount = 0;

    // Convert adjacency matrix into edge list
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges according to weight
    sort(edges, edges + edgeCount,
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    int parent[MAX];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    int count = 0;

    cout << "\nMinimum Spanning Tree using Kruskal's Algorithm:\n";
    cout << "Edge\tCost\n";

    for (int i = 0; i < edgeCount && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        // Add edge only if it does not form a cycle
        if (rootU != rootV)
        {
            cout << u + 1 << " - " << v + 1
                 << "\t" << edges[i].weight << endl;

            totalCost += edges[i].weight;
            unionSet(parent, rootU, rootV);
            count++;
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;
}

  // ---------------- MAIN FUNCTION ----------------

int main()
{
    int graph[MAX][MAX];
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    cout << "Enter 0 if there is no edge.\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    prims(graph, n);
    kruskals(graph, n);

    return 0;
}