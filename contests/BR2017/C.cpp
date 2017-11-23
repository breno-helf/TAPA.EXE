#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 10;

int k, n;
int freq[MAXN];

void solve() {
  set<int> f;
  map<int, int> M;

  for(int i = 1; i <= k; ++i) {
      f.insert(freq[i]);
      ++M[freq[i]];
  }
  
  if(f.size() > 3) {
    printf("*\n");
    return;
  }

  if(f.size() == 3) {
    int x = *f.begin();
    int y = *(--f.end());

    if(y - x != 2) {
      printf("*\n");
      return;
    }

    if(M[x] != 1 || M[y] != 1) {
      printf("*\n");
      return;
    }

    int X, Y;
    for(int i = 1; i <= k; ++i)
      if(freq[i] == x)
	X = i;

    for(int i = 1; i <= k; ++i)
      if(freq[i] == y)
	Y = i;

    printf("-%d +%d\n", Y, X);
    return;
  }

  if(f.size() == 2) {
    int x = *f.begin();
    int y = *(--f.end());
 
    if(y - x > 1) {
      printf("*\n");
      return;
    }

    int id;
    char sign;

    if(M[x] == 1) {
      sign = '+';
      for(int i = 1; i <= k; ++i)
	if(freq[i] == x)
	  id = i;
    }
    else if(M[y] == 1){
      sign = '-';
      for(int i = 1; i <= k; ++i)
	if(freq[i] == y)
	  id = i;
    }
    else {
      printf("*\n");
      return;
    }

    printf("%c%d\n", sign, id);
  }
}

int main() {
  scanf("%d %d", &k, &n);

  for(int i = 1; i <= n; ++i) {
    int num;
    scanf("%d", &num);

    ++freq[num];
  }

  solve();
}
