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
    string x;
    cin >> x;
    string y;
    cin >> y;
    ll arr[26] = {0}, ans = 0;
    for (ll i = 0; i < y.size(); i++)
      arr[y[i] - 97]++;
    for (ll i = 0; i <= x.size() - y.size(); i++)
    {
      ll temp[26] = {0};
      for (ll j = 0; j < y.size(); j++)
        temp[x[i + j] - 97]++;
      bool res = true;
      for (ll j = 0; j < 26; j++)
      {
        if (temp[j] != arr[j])
        {
          res = false;
          break;
        }
      }
      if (res)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
