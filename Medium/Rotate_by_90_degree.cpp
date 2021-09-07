//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix);

// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int>> &matrix)
{
  // Your code goes here
  int n = matrix.size();
  int i = 1;
  for (int j = 0; j < n; ++j)
  {
    for (int k = i; k < n; ++k)
    {
      int x = matrix[j][k];
      matrix[j][k] = matrix[k][j];
      matrix[k][j] = x;
    }
    ++i;
  }

  for (int i = 0, j = n - 1; i < j; ++i, --j)
  {
    for (int k = 0; k < n; ++k)
    {
      int x = matrix[i][k];
      matrix[i][k] = matrix[j][k];
      matrix[j][k] = x;
    }
  }
}

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++)
    {
      matrix[i].resize(n);
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];
    }
    rotate(matrix);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; j++)
        cout << matrix[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}

// } Driver Code Ends
