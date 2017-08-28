#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int G = 1e2 + 10;
const int S = 1e4 + 10;
const int INF = 0x3f3f3f3f;

const int maxn = 1e2 + 10;

int g, c, n;

int type[maxn], p[maxn], s[maxn];

int row;
int dp[2][G][S];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
    cin >> g >> c >> n;
	
    for(int i = 1; i <= n; ++i) {
	string str;
	cin >> str >> p[i] >> s[i];
		
	if(str == "generous") 
	    type[i] = 0;
	else 
	    if(str == "honest") 
		type[i] = 1;
	    else 
		type[i] = 2;
    }
	
    for (int i = 0; i < G; i++)
	for (int j = 0; j < S; j++)
	    dp[0][i][j] = dp[1][i][j] = -INF;
    
    dp[0][c][0] = 0;
	
    for(int i = 1; i <= n; ++i) {
	row ^= 1;
		
	// do not buy from ith merchant 
	for(int gold = 0; gold <= c; ++gold) 
	    for(int silver = 0; silver < S; ++silver)
		dp[row][gold][silver] = max(dp[row][gold][silver], dp[row ^ 1][gold][silver]);

	// buy from him
	for(int gold = 0; gold <= c; ++gold) 
	    for(int silver = 0; silver < S; ++silver) {
		// spend silver coins if possible
		if(silver >= s[i]) 
		    dp[row][gold][silver - s[i]] = max(dp[row][gold][silver - s[i]], 1 + dp[row ^ 1][gold][silver]);
				
		// spend gold coins if possible
		if(gold >= 1 && (type[i] != 0 || silver < s[i])) {
		    if(type[i] == 2) {
			// greedy merchant
			int exchange = g - s[i];
			int P = exchange / p[i];
			dp[row][gold - 1][silver + P * p[i]] = max(dp[row][gold - 1][silver + P * p[i]], 1 + dp[row ^ 1][gold][silver]);
		    }
		    else
			if(!type[i]) {
			    // generous merchant
			    int exchange = g - s[i];
			    int P = exchange / p[i] + (exchange % p[i] != 0);
			    dp[row][gold - 1][silver + P * p[i]] = max(dp[row][gold - 1][silver + P * p[i]], 1 + dp[row ^ 1][gold][silver]);
			}
			else {
			    //honest merchant
			    int exchange = g - s[i];
			    int P = exchange / p[i];
			    int R = exchange % p[i];
							
			    if(2 * R >= p[i])	
				++P;
							
			    dp[row][gold - 1][silver + P * p[i]] = max(dp[row][gold - 1][silver + P * p[i]], 1 + dp[row ^ 1][gold][silver]);
			}
		} 
	    }
				
    }
	
    int ans = 0;
    for(int gold = 0; gold <= c; ++gold)
	for(int silver = 0; silver < S; ++silver) 
	    ans = max(ans, dp[row][gold][silver]);
		
    cout << ans << '\n';
	
    return 0;
}
