#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

set<ll> D;
map<ll, int> fac;
map<int, ll> ID;
int tot = 0;
int cnt = 0;
set<pll> resp;

void generate (int primo, ll val) {
  if (primo == cnt) {
    D.insert(val);
    return;
  }
  int tam = fac[ID[primo]];
  ll pot = 1;
  for (int i = 0; i <= tam; i++) {
    generate(primo + 1, val * pot);
    pot *= ID[primo];
  }
}

int main () {
  cin.sync_with_stdio(false);
  ll k, cur;
  cin >> k;
  cur = k;
  
  for (ll i = 2; i * i <= k; i++) {
    while (cur % i == 0) {
      fac[i]++;
      cur /= i;
    }
  }
  if (cur != 1) fac[cur]++;

  // Debug
  for (auto e : fac) {
    fac[e.first] *= 3;
    ID[cnt] = e.first;
    cnt++;
    tot += fac[e.first];
  }
  
  generate(0, 1);
  D.insert(1);
  for (auto d : D) {
    ll A, B;
    B = k + d;
    if (B - k <= 0) continue;
    if ((B * k) % (B - k) != 0) continue;
    debug("testando %lld\n", B * k);

    A = (B * k) / (B - k);

    resp.insert(pll(A, B));
    resp.insert(pll(B, A));    
  }
  
  cout << resp.size() << '\n';
  
  for (auto e : resp) {
    cout << e.first << ' ' << e.second << '\n';
  }
  return 0;
}
