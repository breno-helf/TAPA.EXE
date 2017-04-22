#include<bits/stdc++.h>
using namespace std;

int a, b, c, d;
int resp;
int main () {
    freopen ("garage.in", "r", stdin);
    freopen ("garage.out", "w", stdout);
    cin >> a >> b >> c >> d;
    resp = ((int)(floor(1.0*a/c) + 1) / 2);
    //cout << resp << '\n';
    resp *= ((int)(floor(1.0*b/d) + 1) / 2);
    cout << resp << '\n';
}
