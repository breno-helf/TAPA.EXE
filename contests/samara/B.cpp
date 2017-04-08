#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;
typedef pair <int,int> pii;

int n;
int freq[maxn];
bool mrk[maxn];
vector<pii>F;

bool acha (int resp, vector<int>last)
{
	for (int i = 0; i < last.size(); ++i)
		if (last[i] == resp)
			return false;
	return true;
}

int main ()
{	
	cin >> n;
	
	int len = (n + 1) / 2;
	int l = 1, r = len;	
	vector <int>last,ans;
	for (int i = 1; i <= len; ++i)
	{
		cout << "Q " << l << " " << r << '\n';
		vector <int> now;
		int falta = -1;
		for (int k = 0; k < len; ++k)
		{
			int resp;
			cin >> resp;
			++freq[resp];
			now.push_back(resp);
		}
		for (int k = 0; k < len; ++k)
		{
			if (i > 1 && acha(last[k], now))
				falta = last[k];
		}
		if (i > 1)
			ans.push_back (falta), mrk[falta] = true;
		last = now;
		++l;
		++r;
	}

	for (int i = 1; i <= n; ++i)
		if (!mrk[i])
			F.push_back (pii(freq[i], i));	
	sort(F.begin(),F.end());
	reverse (F.begin(),F.end());
	for (int i = 0 ; i < F.size(); ++i)
		ans.push_back (F[i].second);
	cout << "A ";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << '\n';

	return 0;
}
