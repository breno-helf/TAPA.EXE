#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f;
const int MAX = 440;

vector<int> adj[MAX];
int p[MAX];
int flow[MAX][MAX];



string a[MAX];
string b[MAX];

int n,m;

int pref(string a){
  int sum = 0;
  for(int i = 0; i < 3; i++){
    sum+=a[i]-'a';
  }
  return sum;
}

int suf(string a){
  int sum = 0;
  for(int i = 3; i < 6; i++){
    sum += a[i] - 'a';
  }
  return sum;
}

bool bfs(int s, int t){
  memset(p,-1,sizeof(p));
  queue <int> q;
  q.push(s);
  p[s]=s;


  while(!q.empty()){
    int at = q.front(); q.pop();
    if(at == t){
      return true;
    }
    for(int i = 0; i < adj[at].size(); i++){
      int nxt = adj[at][i];
      if(p[nxt]==-1 && flow[at][nxt]>0){
	p[nxt]=at;
	q.push(nxt);
      }
    }
  }
  return false;
}

int augment(int s, int t){
  int mn = inf;
  for(int i = t; i != s; i = p[i]){
    mn = min(mn,flow[p[i]][i]);
  }
  for(int i = t; i != s; i = p[i]){
    flow[p[i]][i]-=mn;
    flow[i][p[i]]+=mn;
  }
  return mn;
}

int edmonds(int s, int t){
  int ans = 0;
  while(bfs(s,t)){
    ans += augment(s,t);
  }
  return ans;
}

void find_cut(int s){
  memset(p, 0, sizeof(p));
  for(int i = 1; i <= n; i++){
    for(int j = n + 1; j <= m+n; j++){
      if(flow[j][i] > 0){
	if(pref(b[j-n]) == suf(a[i])){
	  cout << "TA ";
	  cout << b[j-n] <<" " << a[i]<< '\n'; 
	}
	else{
	  // assert(pref(b[j-n])==suf(a[i]));
	  cout<< "AT ";
	  cout << a[i] <<" " << b[j-n]<< '\n';
	}
      }
    }
  }

}


int addedge(int s, int t, int p){
  adj[s].push_back(t);
  flow[s][t]=p;
  adj[t].push_back(s);
  flow[t][s]=0;
}








int main(){
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);

  
  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= m; i++){
    cin >> b[i];
  }

  int s = 0, t = n+m+1 ;
  for(int i = 1; i <= n; i++){
    addedge(0,i,1);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(suf(a[i]) == pref(b[j])|| pref(a[i]) == suf(b[j])){
	addedge(i,n+j,1);
      } 
    }
  }

  for(int i = 1; i <= m; i++){
    addedge(n+i,n+m+1,1);
  }
  cout << edmonds(s,t) << '\n';
  find_cut(s);
  
}
