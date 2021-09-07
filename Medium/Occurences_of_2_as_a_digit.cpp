// C++ program to count 2s from 0 to n
#include <bits/stdc++.h>
using namespace std;

/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d);
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number);

// Driver Coden
int main()
{
  long long int n;
  long long int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    cout << numberOf2sinRange(n) << endl;
  }
  return 0;
}
// } Driver Code Ends

/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d)
{
  // Your code goes here
}

/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
  // Your code goes here
  long long int ans = 0;
  for (long long int i = 2; i <= number; ++i)
  {
    long long int x = i;
    while (x)
    {
      if (x % 10 == 2)
        ++ans;
      x /= 10;
    }
  }
  return ans;
}
