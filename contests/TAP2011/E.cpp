#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)
#define pb push_back

typedef long long ll;

const int MAX = 512;

ll z[MAX];

int main () {
  while (true) {
    ll n;
    cin >> n;
    if (n == -1) break;
    map<ll, int> M;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
      scanf ("%lld", z + i);
      sum += z[i];
      M[z[i]] = 1;
    }
    sort(z + 1, z + n);
    int resp = 0;
    if (sum % (n - 1) == 0 && M[sum / (n - 1)] == 0) {
      int cnt = 0;
      ll val = sum / (n - 1);
      
      for (int i = 1; i < n; i++) {
	if (val > z[i]) cnt++;
      }
      if (cnt == (n - 1) / 2)
	resp++;
    }
    
    ll val = z[(n / 2)] * n - sum;
    
    if (M[val] == 0 && val < z[n / 2]) resp++;

    val = z[1 + (n / 2)] * n - sum;

    if (M[val] == 0 && val > z[1 + n / 2]) resp++;

    cout << resp << '\n';
  }
}
