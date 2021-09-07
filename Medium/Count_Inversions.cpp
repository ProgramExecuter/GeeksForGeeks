#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // arr[]: Input Array
  // N : Size of the Array arr[]
  // Function to count inversions in the array.
  long long merge(long long arr[], long long l, long long mid, long long h)
  {
    // return 0;
    long long n1 = mid - l + 1;
    long long n2 = h - mid;

    long long arr1[n1];
    long long arr2[n2];
    long long cnt = 0;

    for (long long i = 0; i <= n1; ++i)
      arr1[i] = arr[l + i];
    for (long long i = 0; i <= n2; ++i)
      arr2[i] = arr[mid + 1 + i];

    long long i = 0, j = 0, pos = l;
    while (i < n1 && j < n2)
    {
      if (arr1[i] <= arr2[j])
      {
        arr[pos++] = arr1[i++];
      }
      else
      {
        arr[pos++] = arr2[j++];
        cnt += (n1 - i);
      }
    }

    while (i < n1)
    {
      arr[pos++] = arr1[i++];
    }
    while (j < n2)
    {
      arr[pos++] = arr2[j++];
    }
    return cnt;
  }
  long long mergeSort(long long arr[], long long l, long long h)
  {
    if (l >= h)
      return 0;
    long long ans = 0;
    long long mid = l + (h - l) / 2;
    ans += mergeSort(arr, l, mid);
    ans += mergeSort(arr, mid + 1, h);
    ans += merge(arr, l, mid, h);
    return ans;
  }
  long long int inversionCount(long long arr[], long long N)
  {
    // Your Code Here
    long long ans = mergeSort(arr, 0, N - 1);
    // for(int i=0; i<N; ++i)
    //     cout<<arr[i]<<" ";
    // cout<<endl<<"Ans ";
    return ans;
  }
};

// { Driver Code Starts.

int main()
{

  long long T;
  cin >> T;

  while (T--)
  {
    long long N;
    cin >> N;

    long long A[N];
    for (long long i = 0; i < N; i++)
    {
      cin >> A[i];
    }
    Solution obj;
    cout << obj.inversionCount(A, N) << endl;
  }

  return 0;
}
// } Driver Code Ends
