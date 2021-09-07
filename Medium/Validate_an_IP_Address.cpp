#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
  int isValid(string s)
  {
    // code here
    int cntN = 0, num = 0, cntD = 0;
    bool hadNum = false;
    // reverse(s.begin(), s.end());
    for (char ch : s)
    {
      if (ch == '.')
      {
        if (hadNum)
        {
          ++cntD;
          num = 0;
          cntN = 0;
          hadNum = false;
        }
        else
          return 0;
      }
      else if (ch >= 48 && ch <= 57)
      {
        if (num == 0 && cntN > 0)
          return 0;
        ++cntN;
        hadNum = true;
        num = num * 10 + (ch - 48);
        if (!(cntN >= 0 && cntN <= 3) ||
            !(num >= 0 && num <= 255))
          return 0;
      }
      else
        return 0;
    }
    if (cntD != 3)
      return 0;
    return 1;
  }
};

// { Driver Code Starts.

int main()
{
  // your code goes here
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.isValid(s) << endl;
  }
  return 0;
} // } Driver Code Ends