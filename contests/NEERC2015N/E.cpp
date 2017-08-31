#include<bits/stdc++.h>
using namespace std;

string s;
string resp = "";

void solve() {
    if (s[0] != '-' && s[0] != '+') s = "+" + s;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
	if (s[i] == '+') {
	    resp += s[i];
	    int j = i + 1;
	    while (j < n && s[j] >= '0' && s[j] <= '9')
		resp += s[j++];
	    i = j - 1;
	} else if (s[i] == '-'){
	    resp += s[i];
	    resp += s[i + 1];
	    int j = i + 2;
	    while (j < n && s[j] == '0') {
		resp += '+';
		resp += s[j++];
	    }
	    if (j < n && s[j] != '-' && s[j] != '+') {
		resp += '+';
		while (j < n && s[j] >= '0' && s[j] <= '9') resp += s[j++];	
	    }
	    i = j - 1;
	} //else cout << "--> " << s[i] << '\n';
    }
}

int main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    
    cin >> s;
    solve();
    cout << resp << '\n';

    return 0;
}
