
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
  int lps(string s)
  {
    // Your code goes here
    if (s.size() < 2)
      return 0;
    int n = s.size();
    for (int l = n - 1; l >= 1; l--)
    {
      if (s.substr(0, l).compare(s.substr(n - l, l)) == 0)
      {
        return l;
      }
    }
    return 0;
  }
};

// { Driver Code Starts.

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;

    Solution ob;

    cout << ob.lps(str) << "\n";
  }

  return 0;
} // } Driver Code Ends
