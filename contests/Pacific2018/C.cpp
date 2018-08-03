//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e6;

ll a, b;
ll ans = 0;

int main() {
    scanf("%lld%lld", &a, &b);
    
    for (ll i = 1; i <= MAX; i++) {
        // if (crivo[i] == 0) {
        //     for (ll k = i * i; k < MAX; k += i) {
        //         crivo[k] = i;
        //     }
        // }

        for (ll k = ((a + i - 1) / i) * i; k <= b; k += i) {
            ans += i;
            if (i != k / i && k / i > MAX) 
                ans += k / i;
        }
    }
    
    // for (ll k = a; k <= b; k++) {
    //     ans += k + 1;        
    // }
    
    printf("%lld\n", ans);
    return 0;
}

