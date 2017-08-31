#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back

vector<string> eq;

// ll HASH(string s) {
//     ll pow = 1;
//     ll cur = 0;
//     int n = s.size();
//     for (int i = n - 1; i >= 0; i--) {
// 	cur += pow * (ll)s[i];
// 	pow *= 31LL;
//     }
//     return cur;
// }

int main() {
    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);
    
    string s = "";
    for (int i = 0; i < 10; i++) s += "Aa";
    // ll H = HASH(s);
    for (int i = 0; i < (1<<10); i++) {
	string r = "";
	for (int k = 0; k < 10; k++) {
	    if (i & (1<<k)) r += "Aa";
	    else r += "BB";
	}
	eq.pb(r);
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
	printf("%s\n", eq[i].c_str());
}
 
