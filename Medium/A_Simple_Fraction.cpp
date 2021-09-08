#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  string fractionToDecimal(int num, int den)
  {
    if (num == 0)
      return "0";
    int initial = num / den;
    string res;
    res += to_string(initial);
    if (num % den == 0)
      return res;
    res += ".";
    int rem = num % den;
    map<int, int> mp;
    int index;
    bool repeating = false;
    while (rem > 0 && !repeating)
    {
      if (mp.find(rem) != mp.end())
      {
        index = mp[rem];
        repeating = true;
        break;
      }
      else
        mp[rem] = res.size();
      rem = rem * 10;
      int temp = rem / den;
      res += to_string(temp);
      rem = rem % den;
    }
    if (repeating)
    {
      res += ")";
      res.insert(index, "(");
    }
    return res;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int numerator, denominator;
    cin >> numerator >> denominator;
    Solution ob;
    string ans = ob.fractionToDecimal(numerator, denominator);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends
