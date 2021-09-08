using namespace std;
typedef long long int ll;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--)
  {
    //Code
    ll n;
    cin >> n;
    ll pages[n];
    for (ll i = 0; i < n; ++i)
      cin >> pages[i];
    ll capacity;
    cin >> capacity;

    unordered_set<ll> memory;
    vector<ll> temp;

    ll i = 0;
    while (i < n && memory.size() < capacity)
    {
      if (memory.find(pages[i]) == memory.end())
      {
        temp.push_back(pages[i]);
        memory.insert(pages[i]);
      }
      else
      {
        temp.erase(find(temp.begin(), temp.end(), pages[i]));
        temp.push_back(pages[i]);
      }
      ++i;
    }
    // for(auto x : temp)
    //     cout<<x<<" ";
    // cout<<endl;
    if (memory.size() < capacity)
      cout << memory.size() << endl;
    else
    {
      ll ans = capacity;
      while (i < n)
      {
        if (memory.find(pages[i]) == memory.end())
        {
          memory.erase(temp[0]);
          memory.insert(pages[i]);
          temp.erase(temp.begin());
          temp.push_back(pages[i]);
          ++ans;
        }
        else
        {
          temp.erase(find(temp.begin(), temp.end(), pages[i]));
          temp.push_back(pages[i]);
        }
        ++i;
        // for(auto x : temp)
        //     cout<<x<<" ";
        // cout<<" - "<<ans<<endl;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
