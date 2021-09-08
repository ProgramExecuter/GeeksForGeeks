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
    vector<ll> ans;
    ll i = 1;
    ans.push_back(i);
    ll borrow = 0;
    // cout<<n<<endl;
    for (; i <= n; i++)
    {
      for (auto j = ans.begin(); j != ans.end(); j++)
      {
        ll temp = (i * (*j) + borrow) / 10;
        *j = (i * (*j) + borrow) % 10;
        borrow = temp;
      }
      while (borrow != 0)
      {
        ans.push_back(borrow % 10);
        borrow /= 10;
      }
    }
    reverse(ans.begin(), ans.end());
    for (auto i = ans.begin(); i != ans.end(); i++)
      cout << *i;
    cout << endl;
  }

  return 0;
}
