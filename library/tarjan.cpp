int low[MAXN], d[MAXN], sn, st[10*MAXN], tempo; // Iniciar tudo com 0
int marc[MAXN], num;


void scc(int u) {
  st[sn++] = u;
  low[u] = d[u] = tempo++;
  marc[u] = 1;
  for(int v : adj[u]) {
    if(!marc[v]) {
      scc(v);
      low[u] = min(low[u], low[v]);
    }
    else{
      low[u] = min(low[u], d[v]);
    }
  }
  if(low[u] == d[u]) {
    int a = -1;
    int cur = 0;
    while(a != u) {
      a = st[sn - 1];
      cur++;
      d[a] = INF;
      --sn;
      comp[num].pb(a);
    }
    num++;
    // Aqui você pode brincar com os elementos da componente.
    
  }
}
    
