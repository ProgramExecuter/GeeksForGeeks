#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  //Function to find the number of islands.
  void bfs(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &grid)
  {
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({i, j});

    while (!q.empty())
    {
      int a = q.front().first;
      int b = q.front().second;
      q.pop();

      int arr[8][2] = {
          {a - 1, b - 1}, {a - 1, b}, {a - 1, b + 1}, {a, b - 1}, {a, b + 1}, {a + 1, b - 1}, {a + 1, b}, {a + 1, b + 1}};

      for (int it = 0; it < 8; ++it)
      {
        int x = arr[it][0];
        int y = arr[it][1];
        // cout<<x<<" "<<y<<endl;
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
          if (!visited[x][y] && grid[x][y] == '1')
          {
            q.push({x, y});
            visited[x][y] = true;
          }
        }
      }
      // cout<<endl;
    }
  }
  int numIslands(vector<vector<char>> &grid)
  {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (!visited[i][j] && grid[i][j] == '1')
        {
          bfs(i, j, n, m, visited, grid);
          ++ans;
        }
      }
    }

    return ans;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '#'));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    int ans = obj.numIslands(grid);
    cout << ans << '\n';
  }
  return 0;
} // } Driver Code Ends