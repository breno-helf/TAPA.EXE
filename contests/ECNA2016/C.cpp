#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 121;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s, r;
string resp = "";

int main () {
    cin >> s >> r;
    string s2=s;
    for(int i = 0; i < min(s.size(),r.size()); i++){
	char at = (s[i]-'A'-r[i]+'A'+52)%26+'A';
	resp+=at;
    }
    for(int i = r.size(); i < s.size(); i++){
	char at = (s[i]-'A'-resp[i-r.size()]+'A'+52)%26+'A';
	resp+=at;
    }
    cout << resp << '\n';
}

