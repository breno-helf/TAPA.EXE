#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 212345;

int n;
vector<pii> E;
int mrk[MAX];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    E.push_back(pii(a, -i));
    E.push_back(pii(b, i));
  }

  sort(E.begin(), E.end());

  vector<int> ans;
  int cnt = 1;
  for (pii e : E) {
    int id = e.second;
    int T = e.first;
    if (id > 0) {
      //printf("--> %d %d fechando\n", T, id);
      if (mrk[id] == cnt) {
	ans.push_back(T);
	cnt++;
      }
    } else {
      //printf("--> %d %d abrindo\n", T, -id);
      mrk[-id] = cnt;
    }
  }

  printf("%d\n", (int)ans.size());
  for (int T : ans) {
    printf("%d ", T);
  }
  printf("\n");
}
