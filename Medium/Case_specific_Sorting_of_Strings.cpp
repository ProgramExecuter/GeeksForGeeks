#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  //Function to perform case-specific sorting of strings.
  string caseSort(string str, int n)
  {
    // your code here
    string x = str;

    vector<char> small;
    vector<char> caps;
    vector<int> smallIdx;
    vector<int> capsIdx;

    for (int i = 0; i < str.size(); ++i)
    {
      if (str[i] >= 97)
      {
        small.push_back(str[i]);
        smallIdx.push_back(i);
      }
      else
      {
        caps.push_back(str[i]);
        capsIdx.push_back(i);
      }
    }
    sort(caps.begin(), caps.end());
    sort(small.begin(), small.end());

    for (int i = 0; i < small.size(); ++i)
      x[smallIdx[i]] = small[i];
    for (int i = 0; i < caps.size(); ++i)
      x[capsIdx[i]] = caps[i];

    return x;
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
    string str;
    cin >> str;
    Solution obj;
    cout << obj.caseSort(str, n) << endl;
  }
} // } Driver Code Ends
