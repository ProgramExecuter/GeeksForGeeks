//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
  int canReach(int A[], int N)
  {
    // code here
    int s = A[0], pos = 0;
    for (int i = 1; i < N; ++i)
    {
      if (s == 0)
        return 0;
      else
      {
        if (A[i] == 0)
        {
          if (s - (i - pos) >= 0)
          {
            s -= (i - pos);
            pos = i;
          }
          else
            return 0;
        }
        else
        {
          if (A[i] > s - (i - pos))
          {
            s = A[i];
            pos = i;
          }
          else
          {
            s -= (i - pos);
            pos = i;
          }
        }
      }
    }
    return 1;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;

    int A[N];

    for (int i = 0; i < N; i++)
      cin >> A[i];

    Solution ob;
    cout << ob.canReach(A, N) << endl;
  }
  return 0;
} // } Driver Code Ends
