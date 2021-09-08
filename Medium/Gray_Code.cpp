//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
  void solve(vector<string> &ans, int n)
  {
    if (n == 0)
      ans.push_back("");
    else
    {
      solve(ans, n - 1);
      vector<string> tmp;
      tmp = ans;
      ans.clear();
      for (auto i = tmp.begin(); i != tmp.end(); ++i)
        ans.push_back("0" + *i);
      for (auto i = tmp.rbegin(); i != tmp.rend(); ++i)
        ans.push_back("1" + *i);
      tmp.clear();
    }
  }
  vector<string> graycode(int n)
  {
    //code here
    vector<string> ans;
    solve(ans, n);
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

    Solution ob;
    vector<string> ans = ob.graycode(n);
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";

    cout << "\n";
  }
}

// } Driver Code Ends
