#include <bits/stdc++.h>
using namespace std;

struct Item
{
  int value;
  int weight;
};

// } Driver Code Ends

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
  // Your code here
  vector<pair<double, int>> items;
  for (int i = 0; i < n; ++i)
    items.push_back({double((arr[i].value * 1.0) / (arr[i].weight * 1.0)), arr[i].weight});
  sort(items.begin(), items.end());
  reverse(items.begin(), items.end());
  double ans = 0, i = 0;
  while (i < n && W > 0)
  {
    if (items[i].second <= W)
    {
      ans += (items[i].second * items[i].first);
      W -= items[i].second;
    }
    else
    {
      ans += (W * items[i].first);
      W = 0;
    }
    ++i;
  }
  return ans;
}

// { Driver Code Starts.
int main()
{
  int t;
  //taking testcases
  cin >> t;
  cout << setprecision(2) << fixed;
  while (t--)
  {
    //size of array and weight
    int n, W;
    cin >> n >> W;

    Item arr[n];
    //value and weight of each item
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i].value >> arr[i].weight;
    }

    //function call
    cout << fractionalKnapsack(W, arr, n) << endl;
  }
  return 0;
} // } Driver Code Ends
