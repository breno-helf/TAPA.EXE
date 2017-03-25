#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int MAXN=512;

int n, k;
int a, b, resp;

int main () {
  ifstream cin ("input.txt");
  ofstream cout ("output.txt");

  cin >> n >> k;
  a = b = resp = 0;
  a = n;
  while (a || b) {
    if (a >= k) {
      a -= k;
      resp++;
      b += k;
    } else {
      int r = k - a;
      if (b >= r) {
	b -= r;
      } else b = 0;
      b += a;
      a = 0;
      resp++;
    }
  }
  cout << resp << '\n';
}#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int MAXN=512;

int n, k;
int a, b, resp;

int main () {
  ifstream cin ("input.txt");
  ofstream cout ("output.txt");

  cin >> n >> k;
  a = b = resp = 0;
  a = n;
  while (a || b) {
    if (a >= k) {
      a -= k;
      resp++;
      b += k;
    } else {
      int r = k - a;
      if (b >= r) {
	b -= r;
      } else b = 0;
      b += a;
      a = 0;
      resp++;
    }
  }
  cout << resp << '\n';
}
