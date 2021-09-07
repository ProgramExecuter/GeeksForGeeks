#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n)
{
  // Your code here
  int sum = 0;
  int ans = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      ans = max(max(ans, sum), arr[i]);
      if (sum + arr[i] < 0)
        sum = 0;
      else
        sum += arr[i];
    }
    else
    {
      sum += arr[i];
    }
  }
  ans = max(ans, sum);
  return ans;
}

// { Driver Code Starts.

int main()
{
  int t, n;

  cin >> t;   //input testcases
  while (t--) //while testcases exist
  {

    cin >> n; //input size of array

    int a[n];

    for (int i = 0; i < n; i++)
      cin >> a[i]; //inputting elements of array

    cout << maxSubarraySum(a, n) << endl;
  }
}
// } Driver Code Ends
