#include <bits/stdc++.h>

using namespace std;

const int N = 301000;

int timer[N];
double prob[N];

int rtime[N];

priority_queue<int,vector<int>, greater<int>> pq;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d%lf", &timer[i], &prob[i]);
	}

	while(pq.size()<m){
		pq.push(0);
	}

	for(int i = 0; i < n; i++){
		int at = pq.top()+timer[i];
		pq.pop();
		rtime[i] = at;
		pq.push(at);
	}
	double expect = 0;
	double p = 1;
	for(int i = 0; i < n; i++){
		if(i>0)rtime[i]=max(rtime[i],rtime[i-1]);
		expect += (double)rtime[i]*(1.0-prob[i])*p;
		p*=prob[i];
	}
	expect += p*rtime[n-1];
	printf("%lf", expect);
}