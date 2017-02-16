#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 30;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int x[MAX][MAX];
int resp;
set<string> st;

int dig (string s) {
  int tam = s.size();
  int ret = 0;
  for (int i = 0; i < tam; i++) {
    char c = s[i];
    ret = x[ret][c - '0'];
  }
  return ret;
}


int main () {
  cin.sync_with_stdio(false);
  cin.tie(0);

  resp = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> x[i][j];
    }    
  }
  
  for (int i = 0; i <= 9999; i++) {
    string s = "";
    s = to_string(i);
    string t = s;
    
    if (s.size() < 4) {
      reverse(s.begin(), s.end());
      while (s.size() < 4) s += '0';
      reverse(s.begin(), s.end());
    }

    int num = dig(s);
    s += to_string(num);

    for (int k = 0; k < 5; k++) {
      for (int j = 0; j < 10; j++) {
	string r = s;
	r[k] = j + '0';
	if (r == s) continue;
	if (dig(r) == 0) {
	  st.insert(t);
	}
      }
    }

    for (int k = 0; k < 4; k++) {
      string r = s;
      swap(r[k], r[k + 1]);
      if (r == s) {
	continue;
      }
      if (dig(r) == 0) {
	st.insert(t);
      }
    }   
  }

  cout << st.size() << '\n';
  return 0;
}
