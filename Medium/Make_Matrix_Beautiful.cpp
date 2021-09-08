#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  //Function to find minimum number of operations that are required
  //to make the matrix beautiful.
  int findMinOpeartion(vector<vector<int>> matrix, int n)
  {
    // code here
    int row[n] = {0};
    int col[n] = {0};

    int mx = 0, total = 0;
    for (int i = 0; i < n; ++i)
    {
      int sum = 0;
      for (int j = 0; j < n; ++j)
        sum += matrix[i][j];
      row[i] = sum;
      total += sum;
      mx = max(sum, mx);
    }

    for (int j = 0; j < n; ++j)
    {
      int sum = 0;
      for (int i = 0; i < n; ++i)
        sum += matrix[i][j];
      col[j] = sum;
      mx = max(sum, mx);
    }

    return mx * n - total;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];
    Solution ob;
    cout << ob.findMinOpeartion(matrix, n) << endl;
  }
  return 0;
}

// } Driver Code Ends
