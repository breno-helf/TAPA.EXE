#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define debug(args...) //fprintf(stderr, args);
typedef pair<int,int>pii;

const int maxn = 1e3 + 10;

int n;

void print(int r1, int c1, int r2, int c2, char c){
	printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",r1,c1,c,r2,c2);
}

struct ds{
	int open, x, y;
	ds(int open, int x, int y) : open(open), x(x), y(y) {}
};
vector<ds>vec[30];


int main(){
	scanf("%d ",&n);
	int open = 1;
	for(int row = 1; row <= n; ++row){
		string s;
		getline(cin,s);
		debug("row(%d)\n",row);
		for(int pos = 1; pos <= s.size(); ++pos){
			char c = s[pos-1];
			debug("%c\n",c);
			if(c == ' ') continue;
			if(c == '{') ++open;
			else if(c == '}'){
				for(int i = 0; i < 30; ++i)
					if(!vec[i].empty() && vec[i].back().open >= open) 
						vec[i].pop_back();
				--open;
			}
			else{
				int id = c - 'a';
				if(!vec[id].empty()){
					int r2 = vec[id].back().x;
					int c2 = vec[id].back().y; 
					debug("%d (%d,%d)\n",open,r2,c2);
					if(r2 == -1) continue;
					int r1 = row;
					int c1 = pos;
					print(r1,c1,r2,c2,c);
				}
				vec[id].pb(ds(open,row,pos));
			}
		}
	}
	return 0;
}