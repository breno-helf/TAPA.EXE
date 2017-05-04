#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector <int> v[2];
int calc(int n, int val){
	int s = 1, e = n;
	int at = 0;
	for(int i = 0; i < v[val].size() && s != e; i++){
		at += v[val][i];
		if(s+at==0)s++;
		if(e+at==n+1)e--;
	}

	at = s;
	int inut = 0;
	for(int i = 0; i < v[val].size(); i++){
		at =  at + v[val][i];
		if(at == 0){
			inut++;
			at = 1;
		}
		if(at == n+1){
			inut++;
			at = n;
		}
	}
	return inut;

}

char mov[200010];
int main(){
	int t;
	scanf("%d", &t);
	for(int cas = 0; cas < t; cas++){
		v[0].clear();
		v[1].clear();
		int n, m;
		scanf("%d%d",&n,&m);
		scanf(" %s", mov);
		for(int i = 0; mov[i]; i++){
			if(mov[i]=='>')v[0].push_back(1);
			if(mov[i]=='<')v[0].push_back(-1);
			if(mov[i]=='^')v[1].push_back(-1);
			if(mov[i]=='v')v[1].push_back(1);
		}
		printf("%d\n", calc(n, 1) + calc(m, 0));
	}
}
