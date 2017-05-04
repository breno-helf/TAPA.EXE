#include <bits/stdc++.h>
using namespace std;

int t;
string s;
int n, k;

int main ()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    for (cin >> t; t; t--) {
        cin >> n >> k;
        cin >> s;
        bool ok = false;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cur++;
            else cur = 0;

            if (cur == (k + 1)) ok = true;
        }

        if (ok) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}
