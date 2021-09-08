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
    bool found = false;
    for (ll i = n - 2; i >= 0; i--)
    {
      if (arr[i] < arr[i + 1])
      {
        for (ll j = n - 1; j > i; j--)
        {
          if (arr[j] > arr[i])
          {
            ll temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            break;
          }
        }
        sort(arr + i + 1, arr + n);
        found = true;
        break;
      }
    }
    if (!found)
    {
      sort(arr, arr + n);
      reverse(arr, arr + n);
    }
    for (ll i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
  }

  return 0;
}
