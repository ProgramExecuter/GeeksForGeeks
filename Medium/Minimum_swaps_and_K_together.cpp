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
    ll k;
    cin >> k;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
      if (arr[i] <= k)
        cnt++;
    ll c = 0;
    for (ll i = 0; i < cnt; i++)
    {
      if (arr[i] <= k)
        c++;
    }
    ll res = c;
    for (ll i = cnt; i < n; i++)
    {
      if (arr[i - cnt] <= k)
        c--;
      if (arr[i] <= k)
        c++;
      res = max(res, c);
    }
    cout << cnt - res << endl;
  }

  return 0;
}
