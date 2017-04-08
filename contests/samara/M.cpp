#include<bits/stdc++.h>
using namespace std;

int a, b;

int main ()
{
	scanf ("%d%d", &a,&b);
	printf ("%d\n", a*b);
	vector <int> ans;
	for (int i = 1; i <= a * b; i += b )
		for (int j = i + b - 1; j >= i; j--)
			ans.push_back (j);
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
