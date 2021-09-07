#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
  int petrol;
  int distance;
};

// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
  //Function to find starting point where the truck can start to get through
  //the complete circle without exhausting its petrol in between.
  int tour(petrolPump p[], int n)
  {
    //Your code here
    int sum = 0, a[n];
    for (int i = 0; i < n; i++)
    {
      a[i] = p[i].petrol - p[i].distance;
      sum += a[i];
    }
    if (sum < 0)
      return -1;
    sum = 0;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
      sum += a[i];
      if (sum < 0)
      {
        f = i + 1;
        sum = 0;
      }
    }
    return f;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    petrolPump p[n];
    for (int i = 0; i < n; i++)
      cin >> p[i].petrol >> p[i].distance;
    Solution obj;
    cout << obj.tour(p, n) << endl;
  }
}
// } Driver Code Ends