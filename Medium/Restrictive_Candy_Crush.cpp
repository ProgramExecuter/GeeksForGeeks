#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  string Reduced_String(int k, string s)
  {
    // Your code goes here
    string ans = "";
    if (k == 1)
      return ans;
    int cnt = 0;
    stack<pair<char, int>> st;
    for (char ch : s)
    {
      if (st.empty())
      {
        cnt = 1;
        st.push({ch, cnt});
      }
      else
      {
        if (st.top().first == ch)
        {
          cnt = st.top().second + 1;
          st.push({ch, cnt});
          if (cnt == k)
          {
            while (cnt--)
              st.pop();
          }
        }
        else
        {
          cnt = 1;
          st.push({ch, cnt});
        }
      }
    }
    while (!st.empty())
    {
      ans = st.top().first + ans;
      st.pop();
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
    int k;
    cin >> k;
    string s;
    cin >> s;
    Solution obj;
    cout << obj.Reduced_String(k, s) << "\n";
  }

  return 0;
} // } Driver Code Ends
