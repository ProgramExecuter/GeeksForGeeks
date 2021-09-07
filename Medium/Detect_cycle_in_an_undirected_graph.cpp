#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  //Function to detect cycle in an undirected graph.
  bool bfs(int x, int n, vector<int> adj[], vector<bool> &visited)
  {
    queue<pair<int, int>> q;
    q.push({x, -1});
    visited[x] = true;

    while (!q.empty())
    {
      int ele = q.front().first;
      int par = q.front().second;
      q.pop();
      for (auto i : adj[ele])
      {
        if (!visited[i])
        {
          q.push({i, ele});
          visited[i] = true;
        }
        else if (i != par)
          return true;
      }
    }

    return false;
  }
  bool isCycle(int n, vector<int> adj[])
  {
    // Code here
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i)
    {
      if (!visited[i])
      {
        if (bfs(i, n, adj, visited))
          return true;
      }
    }
    return false;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
} // } Driver Code Ends