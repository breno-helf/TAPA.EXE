#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 1123;

char s[MAX][MAX];

bool up (char c) {
    return (c >= 'A' && c <= 'Z');
}

bool low (char c) {
    return (c >= 'a' && c <= 'z');
}

bool alph (char c) {
    return up(c) || low(c);
}

char to_upper(char c) {
    if (low(c))
	return c - 'a' + 'A';
    else return c;
}

char to_lower(char c) {
    if (up(c))
	return c - 'A' + 'a';
    else return c;
}
void solve (string r) {
    if (r.size() % 2) {
	string R = r;
	(reverse(r.begin(), r.end()));
	for (int i = 0; i < (int)r.size(); i++) {
	    if (up(R[i])) {
		r[i] = to_upper(r[i]);
	    } else r[i] = to_lower(r[i]);
	}
	printf ("%s", r.c_str());
    } else {
	string R = r;
	string ff = "", ss = "";
	for (int i = 0; i < (int)r.size(); i++) {
	    if (i < (int)r.size() / 2) ff += r[i];
	    else ss += r[i];
	}

	r = ss + ff;
	
	for (int i = 0; i < (int)r.size(); i++) {
	    if (up(R[i])) {
		r[i] = to_upper(r[i]);
	    } else r[i] = to_lower(r[i]);
	}
	printf ("%s", r.c_str());	
    }
}


int main () {
    int id = 0;
    while (gets(s[id++]));
    // for (int i = 0; i < id; i++) {
    // 	printf ("%s\n", s[i]);
	
    // }
    
    for (int i = 0; i < id; i++) {
    	for (int j = 0; s[i][j] != '\0'; j++) {
    	    string S = "";

    	    while (alph(s[i][j])) {
    		S += s[i][j];
    		j++;
    	    }
	    
    	    if (S != "") solve(S);

    	    if (s[i][j] != '\0') printf ("%c", s[i][j]);
    	}
	if (i != (id - 1))
	    printf("\n");
    }
    return 0;
}
