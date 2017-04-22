#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
ll a, b;
ll resp = 0;

int main () {
    freopen ("energy.in", "r", stdin);
    freopen ("energy.out", "w", stdout);
    a = b = 0;
    resp = 0;
    cin >> n;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            if ((a * 2 + b) < n) {
                b++;
            } else if (a != 0){
                b++;
                a--;
            }
        } else {
            if ((a * 2 + b + 2) <= n) {
                a++;
            }
        }
        resp += (a + b);
    }

    cout << resp << '\n';
}
