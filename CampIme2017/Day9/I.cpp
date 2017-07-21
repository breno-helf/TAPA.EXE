#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

bool prime(ll x){
    if(x == 1) return false;
    for(ll i = 2; i * i <= x; ++i)
	if(x % i == 0) return false;
    return true;
}

int main(){
    ll a, b;
    cin >> a >> b;
    int One = prime(b - a) ? 1 : 0;
    int Two = prime(a + b) ? 1 : 0 + (prime(a - 2LL) && prime(b - 2LL)) ? 1 : 0;
    int Three = (prime(a - 2LL) && prime(b + 2LL)) ? 1 : 0;
    if(One) cout << a << "->" << b << '\n';
    else if(Two == 2)
	cout << "Poor Benny" << '\n';
    else if (Two == 1) {
	if (prime(a + b))
	    cout << a << "->" << a+b << "->" << b << '\n';
	else cout << a << "->" << 2 << "->" << b << '\n';
    }
    else if (Three == 1) cout << a << "->" << 2 << "->" << b + 2 << "->" << b << '\n';
    else cout << "Unlucky Benny\n";
    return 0;
}
