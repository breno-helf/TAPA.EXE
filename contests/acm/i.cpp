#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll T;
ll k, p, q;
ll tamK, tamP, tamQ;
char K[20], P[20], Q[20];

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll dig (ll a) {
    int c = 0;
    while (a) {
	a /= 10;
	c++;
    }
    return c;
}

int main () {
    scanf("%lld", &T);
    for (int t = 1; t <= T; t++) {
	char s[20];
	ll i;
	k = p = q = 0;
	scanf(" %s", s);
	if (s[0] == '.') {
	    k = 0;
	    i = 1;
	    tamK = 0;
	}
	else {
	    for (i = 0; s[i] != '.' && s[i] != '\0'; i++)
		K[i] = s[i];
	    K[i++] = '\0';
	    tamK = i;
	    k = atoll(K);
	}

	ll tam = strlen(s);
	if (s[tam - 1] != ')') {
	    q = 0;
	    ll ini = i;
	    for (; s[i] != '\0'; i++)
		P[i - ini] = s[i];
	    P[i - ini] = '\0';
	    i++;
	    tamP = i - ini - 1;
	    tamQ = 0;
	    p = atoll(P);
	} else {
	    ll ini = i;
	    for (; s[i] != '('; i++)
		P[i - ini] = s[i];
	    P[i - ini] = '\0';
	    i++;
	    tamP = i - ini - 1;
	    p = atoll(P);
	    ini = i;
	    for (; s[i] != ')'; i++)
		Q[i - ini] = s[i];
	    Q[i - ini] = '\0';
	    i++;
	    tamQ = i - ini;
	    q = atoll(Q);
	}
	
	string temp = "";
	ll a, b, z = 0;
	ll x[2], y[2];
	x[1] = y[1] = 1;
	debug(">> %lld %lld %lld\n", k, p, q);
	temp += to_string(k);
	temp += to_string(p);
	y[0] = atoll(temp.c_str());
	temp += to_string(q);
	x[0] = atoll(temp.c_str());
	string Z = ((tamP != 0) ? to_string(p) : "");
	z = Z.size();
	y[1] = 1;
	while(z--) y[1] *= 10;

	debug("~~~ %lld\n", tamP);
	
	Z = ((tamP != 0) ? to_string(p) : "") + to_string(q);
	z = Z.size();
	x[1] = 1;
	while(z--) x[1] *= 10;
	debug("-- %lld %lld %lld %lld\n", x[0], y[0], x[1], y[1]);
	a = x[0] - y[0];
	b = x[1] - y[1];
	ll d = gcd(a, b);
	a /= d;
	b /= d;
	if (p == 0 && q == 0)
	    a /= 10;
	
	printf("Case #%d: %lld/%lld\n", t, a, b);
	debug("\n");
    }
}

