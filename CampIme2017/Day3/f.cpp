#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e2 + 10;

int t;
string s;

int dp[maxn][maxn];
int DP[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];

int Element(int i, int j);

int List(int i, int j){
	if(a[i][j] == -1){
		if(i > j) return a[i][j] = 0;
		a[i][j] = Element(i,j);
		for(int k = i + 1; k <= j - 1; ++k)
			if(s[k] == ',')
				a[i][j] |= (Element(i,k-1) && List(k+1,j));
	}
	return a[i][j];
}

int e(int i, int j) {
	if(DP[i][j] == -1){
		if(i > j) return DP[i][j] = 1;
		DP[i][j] = List(i,j);
	}
	return DP[i][j];
}

int is(int i, int j){
	if(dp[i][j] == -1){
		if(i > j) return dp[i][j] = 0;
		if(s[i] != '{' || s[j] != '}') return dp[i][j] = 0;
		dp[i][j] = e(i+1,j-1);
	}
	return dp[i][j];
}

int main(){
	cin >> t;
	int test = 0;
	while(t--){
		cin >> s;
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		memset(DP,-1,sizeof(DP));
		memset(dp,-1,sizeof(dp));
		cout << "Word #" << ++test << ": ";
		if(is(0,(int)s.size()-1)) cout << "Set\n";
		else cout << "No Set\n";
	}
	return 0;
}

int Element(int i, int j){
	if(b[i][j] == -1){
		if(i > j) return b[i][j] = 0;
		if(i == j) return b[i][j] = 1;
		b[i][j] = is(i,j);
	}
	return b[i][j];
}