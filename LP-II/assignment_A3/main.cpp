#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
#define V 100
int minKey(vector<int> &key, vector<bool> &mstSet)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

void printArray(vi &a)
{
    for (int i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

void primMST(vector<vector<int>> &graph)
{
    vector<int> parent;
    vi key;
    vector<bool> mstSet;
    for (int i = 0; i < graph.size(); i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < graph.size() - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < graph.size(); v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

void primsAlgorithm()
{
    int K;
    // int graph[V][V] = {{0, 2, 0, 6, 0},
    //                    {2, 0, 3, 8, 5},
    //                    {0, 3, 0, 0, 7},
    //                    {6, 8, 0, 0, 9},
    //                    {0, 5, 7, 9, 0}};
            cout << "Enter the number of vertices: ";
            cin >> K;

            cout << "Enter the adjacency matrix:\n";
            vector<vector<int>> graph(K, vector<int>(K));
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    cin >> graph[i][j];
                }
            }
    primMST(graph);
    return;
}
void selectionSort()
{
    int n;
    cout << "Enter the number of elements:\n";
    cin >> n;
    vi a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Array before sorting:\n";
    printArray(a);
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(a[i], a[min]);
        }
        cout<<"\nArray after "<<"pass:"<<i+1<<'\n';
        printArray(a);
    }
    cout << "\nArray after sorting:\n";
    printArray(a);
    return;
}
int main()
{
    int ch;
    while (1)
    {
        cout << "\nSelect one of the following options:\n1. Selection sort.\n2. Prims Algorithm.\n0. Exit\n\n";
        cin >> ch;
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
            selectionSort();
            break;
        case 2:
            primsAlgorithm();
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}