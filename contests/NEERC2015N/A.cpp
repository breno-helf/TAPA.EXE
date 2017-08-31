#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr, args)

int main() {
	freopen("alex.in", "r", stdin);
	freopen("alex.out", "w", stdout);
	double h, w;
	scanf("%lf %lf", &h, &w);
	
	double a = min(h,w);
	double b = max(h,w);
	
	double resp = max(a/2.0, min(b/3.0,a));
	
	printf("%.10lf\n",resp);

}
