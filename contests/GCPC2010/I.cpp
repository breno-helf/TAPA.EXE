#include<bits/stdc++.h>
using namespace std;

set<string> champs;
map<string, int> seen;

int main() {
    int c;
    scanf("%d", &c);
    while(c--) {
	champs.clear();
	seen.clear();
	string s, r;
	int g1, g2;
	for (int i = 0; i < 16; i++) {
	    cin >> s >> r >> g1 >> g2;

	    if (g1 < g2) {
		swap(s, r);
	    }

	    if (champs.find(r) != champs.end()) champs.erase(r);
	    if (seen[s] == 0) {
		champs.insert(s);
	    }
	    seen[r] = seen[s] = 1;
	}

	assert((int)champs.size() == 1);

	for (string k : champs)
	    cout << k << '\n';
    }
}
