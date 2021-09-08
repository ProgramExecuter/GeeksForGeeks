// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends

pair<int, int> JobScheduling(Job arr[], int n)
{
  // your code here
  vector<pair<int, int>> jobs;
  int maxD = 0;
  for (int i = 0; i < n; ++i)
  {
    jobs.push_back({arr[i].profit, arr[i].dead});
    maxD = max(maxD, arr[i].dead);
  }

  sort(jobs.begin(), jobs.end());
  reverse(jobs.begin(), jobs.end());

  bool slots[maxD];
  memset(slots, false, maxD);

  int tasks = 0, profit = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = (jobs[i].second - 1); j >= 0; --j)
    {
      if (!slots[j])
      {
        slots[j] = true;
        profit += jobs[i].first;
        ++tasks;
        break;
      }
    }
  }
  return (make_pair(tasks, profit));
}

// { Driver Code Starts.
// Driver program to test methods
int main()
{
  int t;
  //testcases
  cin >> t;

  while (t--)
  {
    int n;

    //size of array
    cin >> n;
    Job arr[n];

    //adding id, deadline, profit
    for (int i = 0; i < n; i++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      arr[i].id = x;
      arr[i].dead = y;
      arr[i].profit = z;
    }
    //function call
    pair<int, int> ans = JobScheduling(arr, n);
    cout << ans.first << " " << ans.second << endl;
  }
  return 0;
}

// } Driver Code Ends
