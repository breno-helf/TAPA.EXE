#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,string> pis;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s, t;
int v[MAX];


int main () {
    cin.sync_with_stdio(false);
    while (true) {
	cin >> s >> t;
	memset(v, 0, sizeof(v));

	if (s == "*" && t == "*") break;
	
	int tam = s.size();
	for (int i = 0; i < tam; i++) {
	    if (s[i] != t[i]) v[i] = 1;
	}
	int resp = 0;
	int last = 0;
	for (int i = 0; i < tam; i++) {
	    if (v[i] == 1 && last == 0) {
		resp++;
	    }

	    last = v[i];
	}

	cout << resp << '\n';
    }
}

