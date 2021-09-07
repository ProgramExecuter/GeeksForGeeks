#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // arr[]: input array
  // n: size of array
  // Function to find the maximum index difference.
  int maxIndexDiff(int arr[], int n)
  {
    // Your code here
    int left[n], right[n];
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    for (int i = 1; i < n; ++i)
      left[i] = min(left[i - 1], arr[i]);
    for (int i = n - 2; i >= 0; --i)
      right[i] = max(right[i + 1], arr[i]);

    int i = 0, j = 0, ans = 0;
    while (i < n && j < n)
    {
      if (left[i] > right[j])
      {
        ++i;
      }
      else
      {
        ans = max(ans, j - i);
        ++j;
      }
    }
    return ans;
  }
};

// { Driver Code Starts.

/* Driver program to test above functions */
int main()
{
  int T;
  //testcases
  cin >> T;
  while (T--)
  {
    int num;
    //size of array
    cin >> num;
    int arr[num];

    //inserting elements
    for (int i = 0; i < num; i++)
      cin >> arr[i];
    Solution ob;

    //calling maxIndexDiff() function
    cout << ob.maxIndexDiff(arr, num) << endl;
  }
  return 0;
} // } Driver Code Ends
