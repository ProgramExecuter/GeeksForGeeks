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
    if (str.size() % 2 == 1)
    {
      cout << -1 << endl;
      continue;
    }
    stack<char> s;
    ll ans = 0;
    for (char ch : str)
    {
      if (ch == '{')
        s.push(ch);
      else
      {
        if (s.empty())
        {
          ans++;
          s.push('}');
        }
        else
          s.pop();
      }
    }
    if (!s.empty())
      ans += (s.size() / 2);
    cout << ans << endl;
  }

  return 0;
}
