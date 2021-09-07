#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
  int t, n, i, a[100001];
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (i = 0; i < n; i++)
      cin >> a[i];
    cout << findLongestConseqSubseq(a, n) << endl;
  }

  return 0;
} // } Driver Code Ends

// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  int cnt[100005] = {0};
  int mx = INT_MIN;
  for (int i = 0; i < N; i++)
  {
    cnt[arr[i]]++;
    mx = max(arr[i], mx);
  }
  int ans = 0;
  int curr = 0;
  for (int i = 1; i <= mx; i++)
  {
    if (cnt[i] >= 1)
      curr++;
    else
    {
      ans = max(ans, curr);
      curr = 0;
    }
  }
  ans = max(ans, curr);

  return ans;
}