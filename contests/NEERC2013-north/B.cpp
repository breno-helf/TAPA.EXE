#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
const int maxm = 1e3 + 5;
const long double EPS = 1e-8;

int n, m;
string c[maxn];

int votes[maxn];

string S[maxm];

struct pii
{
	string name;
	int votes;
	int id;
	
	pii (string name, int votes, int id) : name(name), votes(votes), id(id) {}
};

bool operator < (pii A, pii B)
{
	return (A.votes > B.votes) || (A.votes == B.votes && A.id < B.id);
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	
	freopen ("bad.in", "r", stdin);
	freopen ("bad.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
		
	for (int i = 1; i <= m; ++i)
		cin >> S[i];

	int invalid = 0;
	
	for (int i = 1; i <= m; ++i)
	{
		int x = 0;
		for (int j = 0; j < n; ++j)
			x += (S[i][j] == 'X');
			
		if (x == 1)
		{
			for (int j = 0; j < n; ++j)
				if (S[i][j] == 'X')
					++votes[j + 1];
		}
		else
			++invalid;
	}
		
	vector <pii> vec;
	
	for (int i = 1; i <= n; ++i)
		vec.push_back (pii (c[i], votes[i], i));
		
	sort (vec.begin(), vec.end());
	
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i].name << " ";
		cout << fixed << setprecision(2) << ( (long double) (vec[i].votes) / (long double) (m) + EPS) * 100.0 << "%\n";
	}
	cout << "Invalid ";
	cout << fixed << setprecision (2) << ((long double) (invalid) / (long double) (m) + EPS) * 100.0 << "%\n";
	
	return 0;
}
