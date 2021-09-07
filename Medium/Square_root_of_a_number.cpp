
long long int floorSqrt(long long int x);

// } Driver Code Ends

// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x)
{
  // Your code goes here
  long long int y = floor(sqrt(x));
  return y;
}

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;
    cout << floorSqrt(n) << endl;
  }
  return 0;
}
// } Driver Code Ends