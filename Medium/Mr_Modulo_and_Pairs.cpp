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
    ll n, k;
    cin >> n >> k;
    ll arr[n], ans = 0;
    for (ll i = 0; i < n; i++)
      cin >> arr[i];
    for (ll i = 0; i < n - 1; i++)
    {
      for (ll j = i + 1; j < n; j++)
      {
        if (arr[i] % arr[j] == k)
          ans++;
        if (arr[j] % arr[i] == k)
          ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
