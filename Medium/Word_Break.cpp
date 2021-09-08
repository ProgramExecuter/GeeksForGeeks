//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<string> dict;
    for (int i = 0; i < n; i++)
    {
      string S;
      cin >> S;
      dict.push_back(S);
    }
    string line;
    cin >> line;
    cout << wordBreak(line, dict) << "\n";
  }
}
// } Driver Code Ends

//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B)
{
  //code here
  int n = A.size();
  int i = 0;
  int j = 0;
  for (; j + i < n; j++)
  {
    // cout<<j<<"-"<<A.substr(i, j+1)<<" ";
    for (auto k = B.begin(); k != B.end(); k++)
    {
      // cout<<"/";
      if (A.substr(i, j + 1).compare(*k) == 0)
      {
        // cout<<",";
        i = i + j + 1;
        j = -1;
        break;
      }
    }
    // cout<<i<<" -> "<<j<<endl;
  }
  if (i == n)
    return 1;
  return 0;
}