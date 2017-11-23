#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 112345;
const int INF = 0x3f3f3f3f;

string s;
vector<int> v;
int mrk[MAX];
int tmp = 0;
int n;
int crivo[MAX];

int test(int x) {
  tmp++;
  for (int k = 0; k < (int)v.size(); k++) {
    int cur = v[k];
    if (mrk[cur] == tmp) continue;
    
    mrk[cur] = tmp;
    cur = (cur + x) % n;
    while (cur != v[k] && s[cur] != 'P') {
      if (mrk[cur] == tmp) break;
      mrk[cur] = tmp;
      cur = (cur + x) % n;
    }

    if (cur == v[k]) {
      //cout << x << endl;
      return 1;
    }
  }
  return 0;
}

int main() {
  cin >> s;
  
  n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      v.pb(i);
    }
  }

  if ((int)v.size() == n) {
    cout << n - 1 << '\n';
    return 0;
  }
  
  int resp = 0;
  
  for (int i = 2; i * i < MAX; i++) {
    if (i == n) break;
    if (crivo[i] == 0) {
      int cur = 0;
      if (n % i == 0) cur += test(i);
      resp += cur;
      
      for (int k = i * i; k < MAX; k += i) {
	if (cur) crivo[k] += i;
	else crivo[k] = -INF;
      }
    } else if (crivo[i] > 0) resp++;    
  }
  
  cout << resp << '\n';
}
