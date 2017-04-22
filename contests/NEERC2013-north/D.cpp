#include <bits/stdc++.h>
using namespace std;

#define debug(args...) // fprintf (stderr, args)

const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;

typedef pair <int, int> pii;

int n, m;

int cont[maxm];
int cost[maxn];

pii P[maxm];
int have[maxm];
vector <int> p[maxn];

long long c[maxn];

struct ds	
{
    int cost, id;
    ds (int cost, int id) : cost(cost), id(id) {}
};

bool operator < (ds A, ds B)
{
    return (A.cost < B.cost) || (A.cost == B.cost && A.id < B.id);
}

bool mrk[maxn];
set <ds> Set;

long long dis[maxn];

long long solve ()
{	
    for (int i = 1; i <= n; ++i)
	{
	    Set.insert (ds (cost[i], i));
	    dis[i] = cost[i];
	}	
	
    while (!Set.empty())
	{
	    int v = Set.begin()->id;
	    debug ("process %d %d\n", Set.begin()->cost, Set.begin()->id);
	    Set.erase (Set.begin());
	    mrk[v] = true;
	    for (int i = 0; i < p[v].size(); ++i)
		{
		    int u = p[v][i];
		    --cont[u];
			
		    if (!cont[u])
			{
			    int x = P[u].first;
			    int y = P[u].second;
			    int z = have[u];
				
			    debug ("relax %d %d %d\n", z, x, y);
				
			    if (mrk[z])
				continue;
				
			    debug ("%d %d %d\n", dis[x], dis[y], dis[z]);
				
			    if (dis[x] + dis[y] < dis[z])
				{
				    Set.erase (Set.find (ds (dis[z], z)));
				    dis[z] = dis[x] + dis[y];
				    Set.insert (ds (dis[z], z));
				}
			}
		}
	}
}

int main ()
{
    ifstream cin ("dwarf.in");
    ofstream cout ("dwarf.out");
	
    cin.sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
	
    cin >> n >> m;
	
    for (int i = 1; i <= n; ++i)
	cin >> cost[i];
		
    for (int i = 1; i <= m; ++i)
	{
	    int x, y, z;
	    cin >> x >> y >> z;
	    have[i] = x;
	    p[y].push_back (i);
	    p[z].push_back (i);
	    cont[i] = 2;
	    P[i] = pii (z, y);
	}
	
    solve();
	
    cout << dis[1] << '\n';
	
    return 0;
}
