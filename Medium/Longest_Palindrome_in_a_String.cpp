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
    string str;
    cin >> str;
    ll n = str.size();
    int arr[n][n];
    memset(arr, 0, sizeof(arr));
    for (ll i = 0; i < n; i++)
    {
      arr[i][i] = 1;
    }
    for (ll i = 1; i < n; i++)
    {
      for (ll j = 0; (j + i) < n; j++)
      {
        if (i > 1)
        {
          if (str[j] == str[i + j] && arr[j + 1][i + j - 1] == 1)
            arr[j][i + j] = 1;
        }
        else
        {
          if (str[j] == str[i + j])
            arr[j][i + j] = 1;
        }
        arr[i + j][j] = arr[j][i + j];
      }
    }
    ll begin = 0;
    ll end = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
      for (ll j = 0; (j + i) < n; j++)
      {
        if (arr[j][i + j] == 1)
        {
          begin = j;
          end = i + j;
          goto xy;
        }
      }
    }
  xy:
    cout << str.substr(begin, end - begin + 1) << endl;
  }

  return 0;
}
