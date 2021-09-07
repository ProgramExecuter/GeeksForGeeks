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
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
      cin >> arr[i];

    ll ans = 0;
    ll maxLeft[n] = {0};
    ll maxRight[n] = {0};
    ll mx = arr[0];
    for (ll i = 1; i < n - 1; i++)
    {
      maxLeft[i] = mx;
      if (arr[i] > mx)
        mx = arr[i];
    }
    mx = arr[n - 1];
    for (ll i = n - 2; i > 0; i--)
    {
      maxRight[i] = mx;
      if (arr[i] > mx)
        mx = arr[i];
    }

    for (ll i = 1; i < n - 1; i++)
    {
      ll temp = min(maxLeft[i], maxRight[i]);
      if (temp > arr[i])
        ans += (temp - arr[i]);
    }
    cout << ans << endl;
  }
  return 0;
}