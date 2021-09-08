#include <bits/stdc++.h>

using namespace std;

#define ll long long

// } Driver Code Ends
//User function template for C++

// #define ll long long
class Solution
{
public:
  vector<ll> factorial(vector<ll> a, int n)
  {
    ll fact[100005] = {1};
    ll temp = 1, mx = -1;
    for (int x : a)
    {
      mx = x > mx ? x : mx;
    }
    for (int i = 1; i <= mx; ++i)
    {
      temp *= i;
      temp %= 1000000007;
      fact[i] = temp;
    }
    for (int i = 0; i < n; ++i)
    {
      a[i] = fact[a[i]];
    }
    return a;
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
    vector<ll> a(n);
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    Solution ob;
    vector<ll> res = ob.factorial(a, n);
    for (i = 0; i < n; i++)
    {
      cout << res[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
