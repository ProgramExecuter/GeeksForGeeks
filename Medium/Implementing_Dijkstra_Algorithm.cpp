#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  //Function to find the shortest distance of all the vertices
  //from the source vertex S.
  int findMinVer(int V, vector<bool> &visited, vector<int> &dist)
  {
    int min = INT_MAX;
    int vertex;
    for (int i = 0; i < V; i++)
    {
      if (visited[i] == false && dist[i] < min)
      {
        vertex = i;
        min = dist[i];
      }
    }
    return vertex;
  }
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    vector<bool> visited(V, false);
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    for (int i = 0; i < (V - 1); i++)
    {
      int u = findMinVer(V, visited, dist);
      visited[u] = true;
      for (auto v : adj[u])
      {
        if (!visited[v[0]] && (dist[u] + v[1]) < dist[v[0]])
        {
          dist[v[0]] = dist[u] + v[1];
        }
      }
    }
    return dist;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
      int u, v, w;
      cin >> u >> v >> w;
      vector<int> t1, t2;
      t1.push_back(v);
      t1.push_back(w);
      adj[u].push_back(t1);
      t2.push_back(u);
      t2.push_back(w);
      adj[v].push_back(t2);
    }
    int S;
    cin >> S;

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
      cout << res[i] << " ";
    cout << endl;
  }

  return 0;
}

// } Driver Code Ends
