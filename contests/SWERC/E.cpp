#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb emplace_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
ll  PR1 = 1000081;
ll  PR2 = 1091;

set < pii > known;
int n;

bool isToken (string& s) {
    // . , : ; ? !
    if (s == "." || s == "," || s == ":" || s == ";"
	|| s == "?" || s == "!") return true;

    return false;
}

string lower (string s) {
    int tam = s.size();
    for (int i = 0; i < tam; i++)
	s[i] = tolower(s[i]);
    return s;
}

pll getHash (string& s) {
    ll fst = 0;
    ll snd = 0;
    int tam = s.size();
    ll POW1 = PR1, POW2 = PR2;
    for (int i = 0; i < tam; i++) {
	fst = (fst * POW1 + ((ll)s[i])) % MOD;
	snd = (snd * POW2 + ((ll)s[i])) % MOD;
    }
    return pll(fst, snd);
}

void learn (vector<string>& sentence) {
    int tam = sentence.size();
	    
    for (int size = 1; size <= n; size++) {
	for (int ed = size; ed <= tam; ed++) {
	    string s = "";
	    for (int i = ed - size; i < ed; i++) {
		s += lower(sentence[i]);
		if (i != (ed - 1)) s += " ";
	    }
	    known.insert(getHash(s));
	}		
    }
}

void asks (vector<string>& sentence) {
    int tam = sentence.size();

    bool ok = true;
    
    for (int size = 1; size <= n; size++) {
	for (int ed = size; ed <= tam; ed++) {
	    string s = "";
	    string p = "";
	    for (int i = ed - size; i < ed; i++) {
		s += lower(sentence[i]);
		p += sentence[i];
		if (i != (ed - 1)) {
		    s += " ";
		    p += " ";
		}
	    }

	    if (known.find(getHash(s)) == known.end()) {
		if (size == 1) {
		    cout << "What does the word " << "\"" << p << "\"" << " mean?\n";
		}
		ok = false;
		known.insert(getHash(s));
	    }
	}		
    }

    if (ok == false && sentence.size() > 1) {
	string s = "";
	for (int i = 0; i < tam; i++) {
	    s += sentence[i];
	    if (i != (tam - 1)) s += " ";
	}
	cout << "What does the sentence " << "\"" << s << "\"" << " mean?\n";
    }
}

int main () {
    int Case = 1;
    
    
    while (cin >> n) {
	string cur;
	vector<string> sentence;
	known.clear();
	sentence.pb("joe");
	learn(sentence);
	sentence.clear();

	cout << "Learning case " << Case++ << "\n";
	
	cin >> cur;
	while (cur != "*") {
	    while (isToken(cur) == false && cur != "*") {
		sentence.pb(cur);
		cin >> cur;
	    }
	    learn(sentence);
	    sentence.clear();
	    if (cur == "*") break;
	    cin >> cur;
	}
	
	cin >> cur;
	while (cur != "#") {
	    while (isToken(cur) == false && cur != "#") {
		sentence.pb(cur);
		cin >> cur;
	    }
	    asks(sentence);
	    learn(sentence);
	    sentence.clear();
	    if (cur == "#") break;
	    cin >> cur;
	}
	cout << "\n";
    }

    return 0;
}
