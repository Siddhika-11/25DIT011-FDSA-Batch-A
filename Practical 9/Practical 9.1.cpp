#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<vector<int>> &graph, vector<int> &visited)
{
    visited[node] = 1;
    cout << node << " ";

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];

        if (visited[next] == 0)
            DFS(next, graph, visited);
    }
}

void BFS(int start, vector<vector<int>> &graph)
{
    vector<int> visited(graph.size(), 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];

            if (visited[next] == 0)
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<int> visited(n, 0);

    cout << "DFS: ";
    DFS(start, graph, visited);

    cout << "\nBFS: ";
    BFS(start, graph);

    return 0;
}

