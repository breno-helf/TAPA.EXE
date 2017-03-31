#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
long long const int MOD = 1e9 + 7;

string s;
long long dp[MAXN];

long long solve (int p)
{
    if (dp[p] == -1)
    {
        if (p == s.size())
            return (dp[p] = 1);
            
        dp[p] = solve (p + 1);
        
        if (s[p] == 'N' || s[p] == 'S')
            if (p + 1 < s.size() && (s[p + 1] == 'W' || s[p + 1] == 'E'))
                dp[p] = (dp[p] + solve (p + 2)) % MOD;
    }
    
    return dp[p];
}

int main ()
{
    cin.sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    
    cin >> s;
    
    memset (dp, -1, sizeof (dp));
    cout << solve(0) << '\n';
    return 0;
}
