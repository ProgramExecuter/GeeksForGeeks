#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to return Next larger elements

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
  // Your code here
  stack<int> s;
  s.push(0);
  long long currMax = arr[0];
  vector<long long> res(n, -1);
  for (int i = 1; i < n; ++i)
  {
    if (arr[i] > arr[s.top()])
    {
      while (!s.empty() && arr[i] > arr[s.top()])
      {
        res[s.top()] = arr[i];
        s.pop();
      }
      s.push(i);
      currMax = arr[i];
    }
    else
      s.push(i);
  }
  return res;
}

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    vector<long long> res = nextLargerElement(arr, n);
    for (long long i : res)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
