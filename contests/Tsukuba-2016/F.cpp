#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

const int N = 400;

map <string, int> mp;
vector<int> par[N][N];
vector<int> src[1010];
vector<int> dst[1010];

int reach[N][N];
int done[1010];

int qtd=0;

int read(){
    string a;
    cin >> a;
    if(mp.find(a)==mp.end()){
	mp[a]=qtd++;
	return qtd-1;
    }
    else{
	return mp[a];
    }
}




int main(){
    int a = read(), b = read();
    int n;
    scanf("%d", &n);
    reach[a][b]=1;
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    for(int i = 0; i < n; i++){
	int val;
	scanf("%d", &val);
	for(int j = 0; j < val; j++){
	    a = read(), b = read();
	    src[i].push_back(a);
	    dst[i].push_back(b);
	    par[a][b].push_back(i);
	}
    }

    while(!q.empty()){
	pair<int,int> f = q.front();
	int x = f.first;
	int y = f.second;
	q.pop();
	for(int i = 0; i < par[x][y].size(); i++){
	    int nxt = par[x][y][i];
	    if(done[nxt])continue;
	    done[nxt]=1;
	    for(int j = 0; j < src[nxt].size(); j++){
		int nx = src[nxt][j];
		int ny = dst[nxt][j];
		if(!reach[nx][ny]){
		    reach[nx][ny]=1;
		    q.push(make_pair(nx,ny));
		}
	    }
	}

	for(int i = 0; i < qtd; i++){
	    if(reach[i][x] && !reach[i][y]){
		reach[i][y] = 1;
		q.push(make_pair(i,y));
	    }
	}
	for(int i = 0; i < qtd; i++){
	    if(reach[y][i] && !reach[x][i]){
		reach[x][i] = 1;
		q.push(make_pair(x,i));
	    }
	}			
    }
    int ok = 1;
    for(int i = 0; i < qtd; i++){
	if(reach[i][i])ok=0;
    }
    puts(ok ? "Yes" : "No");


}
