#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 1001000; 
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000009;

int n;

int complete, lixo;

struct BITsum
{
	int bit[N];
	
	void init ()
	{
		for (int i = 1; i <= n; i++)
			bit[i] = 0;
	}
	
	void add (int idx, int val)
	{
	       if(idx==0)return;
		while (idx < N)
		{
			bit[idx] += val;
			idx += (idx & -idx);
		}
	}
	
	int get (int idx)
	{
		int ret = 0;
		
		while (idx > 0)
		{
			ret += bit[idx];
			idx -= (idx & -idx);	
		}	
		
		return ret;
	}
	
	int resp (int pos)
	{
		return get (pos) - get (pos - 1); 
	}
	
	void range (int l, int r)
	{
		add (l, +1);
		add (r + 1, -1);
	}
	
} ans;


bool verify(int val){
  if(complete) return false;
  else if(ans.get(val) != val){
    return true;
  }
  else if(ans.get(val) == val && (lixo+ ans.get(n)-ans.get(val))==0){
    complete = 1;
    return true;
  }
  else return false;
}


void update(int val){
  ans.add(val,1);
  while(val>0&&ans.resp(val)==2){
    ans.add(val,-2);
    val--;
    ans.add(val,1);
  }
}


int main(){
  scanf("%d", &n);
  //comp[0]=1;

  lixo = 0;
  complete = 0;
  
  for(int i = 0; i < n; i++){
    int val;
    scanf("%d",&val);
    if(val<1000000){
      if(verify(val)){
	puts("Yes");
	update(val);
      }
      else puts("No");
    }
    else{
      lixo++;
      if(complete)printf("No\n");
      else printf("Yes\n");

    }
  }
}
