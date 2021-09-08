//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution
{
public:
  int median(vector<vector<int>> &matrix, int r, int c)
  {
    // code here
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < r; ++i)
    {
      mn = min(mn, matrix[i][0]);
      mx = max(mx, matrix[i][c - 1]);
    }
    while (mn < mx)
    {
      int mid = mn + ((mx - mn) / 2);
      int cnt = 0;
      int target = (r * c + 1) / 2;
      for (int j = 0; j < r; ++j)
      {
        cnt += upper_bound(matrix[j].begin(), matrix[j].end(), mid) - matrix[j].begin();
      }
      // cout<<i<<" "<<cnt<<endl;

      if (cnt < target)
        mn = mid + 1;
      else
        mx = mid;
    }
    return mn;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        cin >> matrix[i][j];
    Solution obj;
    cout << obj.median(matrix, r, c) << endl;
  }
  return 0;
} // } Driver Code Ends
