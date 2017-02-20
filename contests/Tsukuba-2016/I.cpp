#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;


ll gcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1;y=0;return a;}
    ll ans = gcd(b,a%b,x,y);
    ll t = x; x = y; y = t - a/b*y;
    return ans;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
	ll a, b, x, y;
	scanf("%lld%lld", &a, &b);

	ll d = gcd(a,b,x,y);

	if(d <= 50000){
	    printf("%d\n",3);
	    printf("%d %d\n",0,0);
	    if(x<=0){
		printf("%lld %lld\n",y,-x);
		assert(y>=0);
		assert(y<=a);
		assert(-x>=0);
		assert(-x<=b);

	    }
	    else{
		printf("%lld %lld\n",-y,x);
		assert(-y>=0);
		assert(-y<=a);
		assert(x>=0);
		assert(x<=b);					
	    }
	    printf("%lld %lld\n",a,b);
	}
	else{
	    printf("%d\n",4);
	    printf("%d %d\n",0,0);
	    printf("%lld %lld\n",a-1,b);
	    printf("%lld %lld\n",a/d,b/d);
	    printf("%lld %lld\n",a,b-1);
	}
    }
}
