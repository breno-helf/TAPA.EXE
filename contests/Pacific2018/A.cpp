//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;
vector<string> subs;

int main() {
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        string cur = "";
        for (int j = i; j < (int)s.size(); j++) {
            cur += s[j];
            subs.push_back(cur);
        }        
    }

    for (string str : subs) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (rev == str && ((int)str.size() % 2 == 0)) {
            printf("Or not.\n");
            return 0;
        }
    }

    printf("Odd.\n");

    return 0;
}

