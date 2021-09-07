
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
  int ans = 0;
  bool flag = true;
  int i = 0;
  while (i < n - 1)
  {
    int max = 0;
    int pos = -1;
    if (i + arr[i] >= n - 1)
    {
      ans++;
      break;
    }
    for (int j = i + 1; j <= i + arr[i]; j++)
    {
      if (arr[j] != 0 && arr[j] >= max)
      {
        max = arr[j];
        pos = j;
      }
      else
      {
        if ((arr[j] + j - pos) > max)
        {
          max = arr[j];
          pos = j;
        }
      }
    }
    if (max == 0)
    {
      flag = false;
      break;
    }
    else
    {
      ans++;
      i = pos;
    }
  }
  if (flag)
    return ans;
  return -1;
}

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i, j;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    cout << minJumps(arr, n) << endl;
  }
  return 0;
}
// } Driver Code Ends