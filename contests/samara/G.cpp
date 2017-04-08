#include <bits/stdc++.h>

const int MAXN = 100100; 
using namespace std;

long long val[MAXN];
int mult[MAXN];
int main(){
	int coin, tot;
	scanf("%d %d",&coin, &tot);

	val[0]=1;
	for(int i = 1; i <= coin; i++){
		scanf("%d",&mult[i]);
	}
	int j;
	for(j = 1; j <= coin; j++){
		val[j]=val[j-1]*mult[j];
		if(val[j] > tot) break;
	}
	int ans = 0;
	for(int i = j-1; i >= 0 ; i--){
		ans += tot/val[i];
		tot%=val[i];
	}
	printf("%d\n",ans);

	

}
