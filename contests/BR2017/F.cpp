#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int n;

map<pii, ll> m;

ll seg[4 * maxn];

void update(int idx, int i, int j, int pos, ll val) {
  if(i == j) {
    seg[idx] = max(seg[idx], val);
    return;
  }

  int mid = (i + j) >> 1;
  int left = idx << 1;
  int right = left | 1;
  
  if(pos <= mid)
    update(left, i, mid, pos, val);
  else
    update(right, mid + 1, j, pos, val);

  seg[idx] = max(seg[left], seg[right]);
}

ll query(int idx, int i, int j, int l, int r) {
  if(i > j || j < l || r < i || l > r)
    return 0;

  if(l <= i && j <= r)
    return seg[idx];

  int mid = (i + j) >> 1;
  int left = idx << 1;
  int right = left | 1;

  return max(query(left, i, mid, l, r), query(right, mid + 1, j, l, r));
}

int id;
map<int, int> Map;

ll solve() {
  vector<int> arr;
  vector<pii> P;

   for(auto i: m) {
    pii p = i.first;
    
    P.push_back(p);
    arr.push_back(p.second);
  }

  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  for(auto i: arr)
    Map[i] = ++id;

  ll ans = 0;
  
  for(int i = 0; i < (int)P.size(); ++i) {
    int x = P[i].first;
    int j = i;

    while(j < (int) P.size() && P[j].first == x) 
      ++j;

    for(int k = j - 1; k >= i; --k) {
      int y = P[k].second;
      int pos = Map[y];
      ll d = m[P[k]];

      ll q = query(1, 1, id, 1, pos - 1) + d;
      ans = max(ans, q);
      update(1, 1, id, pos, q); 
    }
    
    i = j - 1;
  }

  return ans;
}

int main() {
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i) {
    int x, y;
    ll d;
    scanf("%d %d %lld", &x, &y, &d);

    pii p = {x, y};
    m[p] += d;
  }

  printf("%lld\n", solve());
  return 0;
}
