#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int128_t ll;
class Solution
{
public:
  // Function to find maximum product subarray
  long long maxProduct(int *a, int n)
  {
    // code here
    int128_t cur = 1;
    int128_t ans = INT_MIN;

    for (long long i = 0; i < n; i++)
    {
      cur *= (int128_t)a[i];
      ans = (int128_t)max(cur, ans);

      if (a[i] == 0)
      {
        cur = 1;
      }
    }

    cur = 1;
    for (long long i = n - 1; i >= 0; i--)
    {
      cur *= (int128_t)a[i];
      ans = (int128_t)max(cur, ans);

      if (a[i] == 0)
      {
        cur = 1;
      }
    }

    return (long long)ans;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.maxProduct(arr, n);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends
