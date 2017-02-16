#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;

pii a[MAX];

int main () {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    a[i].second = i + 1;
    a[i].first = 0;
  }
  int turn = -1;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    --q;
    a[q].first = turn--;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    cout << a[i].second << '\n';
  return 0;
}
