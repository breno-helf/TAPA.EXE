//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 21234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int m;
int b, s[MAX];

bool good() {
    int qtd = 0;
    for (int i = 1; i <= b; i++) {
	if (s[i] % 2 == 1) {
	    qtd++;
	}
    }

    if (qtd % 2) return false;

    
    int cur = 0;
    for (int i = b; i >= 1; i--) {
	int games = 0;
	if (s[i] % 2) games++;

	if((b - 1 - games - s[i]/2) < 0) return false;
 	cur -= (b - 1 - games - s[i]/2);	
	cur += s[i] / 2;
    }
    
    return (cur == 0);
}

int main() {
    while(scanf("%d", &m) != EOF) {
	for (int u = 0; u < m; u++) {
	    scanf("%d", &b);
	    for (int i = 1; i <= b; i++) scanf("%d", s + i);
	    sort(s + 1, s + b + 1);
	    if (good()) puts("T");
	    else puts("F");
	}
    }
    return 0;
}

