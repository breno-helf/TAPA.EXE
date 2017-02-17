#include <bits/stdc++.h>
using namespace std;

#define debug(args...) // fprintf (stderr, args)

const int N = 2e5 + 10;

typedef pair <int, int> pii;

int n, m;

int L[N], R[N];
int LIS[N], LDS[N];

int ans[N];

vector <pii> E;

void solve ()
{
  sort (E.begin(), E.end());
  reverse (E.begin(), E.end());

  for (auto i: E)
  {
    int y = i.second;

    debug ("%d\n", y);

    LIS[y] = max (LIS[y], LIS[y - 1] + 1);
    LDS[y] = max (LDS[y], LDS[y + 1] + 1);
  }

  for (int i = 1; i <= n - 1; i++)
  {
    int y1 = i;
    int y2 = i + 1;

    L[y1] = max (L[y1], LIS[i]);
    L[y2] = max (L[y2], LIS[i] + 1);

    R[y1] = max (R[y1], LDS[i] + 1);
    R[y2] = max (R[y2], LDS[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    int l = i - L[i] + 1;
    int r = i + R[i] - 1;

    ans[l]++;
    ans[r + 1]--;
  }

  int sum = 0;
  for (int i = 0; i <= n; i++)
  {
    sum += ans[i];
    ans[i] = sum;
  }
}

int main ()
{
  cin.sync_with_stdio (false);
  cin.tie (0);
  cout.tie (0);

  cin » n » m;

  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin » x » y;

    E.push_back (pii (x, y));
  }

  solve ();

  for (int i = 1; i <= n; i++)
    cout « max (1, ans[i]) « " ";
  cout « '\n';

  return 0;
}
