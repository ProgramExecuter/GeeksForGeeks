#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int *findTwoElement(int *arr, int n)
  {
    // code here
    int xAB = arr[0];
    for (int i = 1; i < n; ++i)
      xAB ^= arr[i];
    for (int i = 1; i <= n; ++i)
      xAB ^= i;

    int setBit = xAB & ~(xAB - 1);

    int a = 0, b = 0;
    for (int i = 0; i < n; ++i)
    {
      if (arr[i] & setBit)
        a ^= arr[i];
      else
        b ^= arr[i];
    }
    for (int i = 1; i <= n; ++i)
    {
      if (i & setBit)
        a ^= i;
      else
        b ^= i;
    }

    int *ans = new int[2];
    for (int i = 0; i < n; ++i)
    {
      if (arr[i] == a)
      {
        ans[0] = a;
        ans[1] = b;
        break;
      }
      else if (arr[i] == b)
      {
        ans[0] = b;
        ans[1] = a;
        break;
      }
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    Solution ob;
    auto ans = ob.findTwoElement(a, n);
    cout << ans[0] << " " << ans[1] << "\n";
  }
  return 0;
} // } Driver Code Ends
