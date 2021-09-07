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
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    for (ll i = 0; i < n; i++)
      cin >> arr[i];
    bool ans = false;
    if (n < 3)
    {
      cout << 0 << endl;
      continue;
    }
    sort(arr, arr + n);
    for (ll i = 0; i < n - 2; i++)
    {
      if (x < arr[i])
        break;
      ll j = i + 1;
      ll k = n - 1;
      while (j < k)
      {
        if ((arr[j] + arr[k]) > (x - arr[i]))
          k--;
        else if ((arr[j] + arr[k]) < (x - arr[i]))
          j++;
        else
        {
          // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
          ans = true;
          goto xy;
        }
      }
      if (false)
      {
      xy:
        break;
      }
    }
    if (ans)
      cout << 1;
    else
      cout << 0;
    cout << endl;
  }

  return 0;
}