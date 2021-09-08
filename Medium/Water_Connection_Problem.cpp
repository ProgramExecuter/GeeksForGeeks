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
    ll n, p;
    cin >> n >> p;

    bool isStart[n + 1];
    memset(isStart, true, n + 1);

    ll diameter[n + 1];
    memset(diameter, 0, (n + 1) * sizeof(ll));

    ll links[n + 1];
    memset(links, 0, (n + 1) * sizeof(ll));

    for (ll i = 0; i < p; ++i)
    {
      ll x, y, z;
      cin >> x >> y >> z;
      isStart[y] = false;
      diameter[y] = z;
      links[x] = y;
    }

    vector<vector<ll>> ans;

    for (ll i = 1; i <= n; ++i)
    {
      if (isStart[i] && links[i] != 0)
      {
        ll st = i, en = links[i];
        ll curr = en, mnD = diameter[en];
        while (links[curr] != 0)
        {
          en = links[curr];
          mnD = min(mnD, diameter[en]);
          curr = en;
        }
        vector<ll> tmp;
        tmp.push_back(st);
        tmp.push_back(en);
        tmp.push_back(mnD);
        ans.push_back(tmp);
      }
    }
    cout << ans.size() << endl;
    for (ll i = 0; i < ans.size(); ++i)
      cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
  }
  return 0;
}
