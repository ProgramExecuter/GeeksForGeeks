//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
  // bool isBalanced(string s)
  // {
  //     stack<char> st;
  //     for(int i=0; i<s.size(); ++i)
  //     {
  //         char x = s[i];
  //         if(x == ')')
  //         {
  //             if(st.empty() || st.top() != '(')
  //                 return false;
  //             st.pop();
  //         }
  //         else
  //             st.push('(');
  //     }
  //     if(st.empty())
  //         return true;
  //     return false;
  // }
  void allPerm(int n, string s, int l, int r, vector<string> &ans)
  {
    if (l > n || r > n || r > l)
      return;
    if (s.length() == 2 * n && l == r)
      ans.push_back(s);
    allPerm(n, s + '(', l + 1, r, ans);
    allPerm(n, s + ')', l, r + 1, ans);
  }
  vector<string> AllParenthesis(int n)
  {
    // Your code goes here
    vector<string> ans;
    allPerm(n, "", 0, 0, ans);

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
    vector<string> result = ob.AllParenthesis(n);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i)
      cout << result[i] << "\n";
  }
  return 0;
}
// } Driver Code Ends
