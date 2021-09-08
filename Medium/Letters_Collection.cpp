// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
  {
    // code here
    vector<int> ans;
    for (int x = 0; x < q; ++x)
    {
      vector<pair<int, int>> que;
      int i = queries[x][1];
      int j = queries[x][2];

      if (queries[x][0] == 1)
      {
        int arr[8][2] = {
            {i - 1, j - 1},
            {i - 1, j},
            {i - 1, j + 1},
            {i, j - 1},
            {i, j + 1},
            {i + 1, j - 1},
            {i + 1, j},
            {i + 1, j + 1},
        };

        for (int it = 0; it < 8; ++it)
          que.push_back({arr[it][0], arr[it][1]});
      }
      else
      {
        int arr[16][2] = {
            {i - 2, j - 2},
            {i - 2, j - 1},
            {i - 2, j},
            {i - 2, j + 1},
            {i - 2, j + 2},
            {i - 1, j - 2},
            {i, j - 2},
            {i + 1, j - 2},
            {i - 1, j + 2},
            {i, j + 2},
            {i + 1, j + 2},
            {i + 2, j - 2},
            {i + 2, j - 1},
            {i + 2, j},
            {i + 2, j + 1},
            {i + 2, j + 2},
        };

        for (int it = 0; it < 16; ++it)
          que.push_back({arr[it][0], arr[it][1]});
      }

      int sum = 0;
      for (int it = 0; it < que.size(); ++it)
      {
        // cout<<que[it].first<<" "<<que[it].second<<endl;
        if (que[it].first >= 0 && que[it].first < n &&
            que[it].second >= 0 && que[it].second < m)
          sum += mat[que[it].first][que[it].second];
      }
      // cout<<endl;
      ans.push_back(sum);
    }
    return ans;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, q, ty, i, j;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> mat[i][j];
    cin >> q;
    vector<int> queries[q];
    for (int k = 0; k < q; k++)
    {
      cin >> ty >> i >> j;
      queries[k].push_back(ty);
      queries[k].push_back(i);
      queries[k].push_back(j);
    }

    Solution ob;
    vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
    for (int u : ans)
      cout << u << "\n";
  }
  return 0;
} // } Driver Code Ends
