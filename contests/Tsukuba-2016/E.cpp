#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back

string a;

vector <char> v;
vector <char> op;

int fat[10];
string n;
int ok, cur;


char x[]={'0','1','+','-','*','(',')','='};

int islet(char a){
    if('a'<= a && a <= 'z')return 1;
    if('A'<= a && a <= 'Z')return 1;
    return 0;
}

void eatnxt(char c){
    if(cur==n.size() || n[cur] != c)
	ok = 0;
    ++cur;
}

bool tryeatnxt(char c){
    if(cur!=n.size() && n[cur] == c){
	++cur;
	return 1;
    }
    return 0;
}

void pQ();int pE(int sign =1);int pT();int pF();

void pQ(){
    int A = pE(1);
    eatnxt('=');
    int B = pE(1);
    if(A!=B || cur!=n.size())
	ok=0;
}

int pE(int sign){
    int a = sign * pT();
    if(tryeatnxt('+'))
	return a + pE(1);
    if(tryeatnxt('-'))
	return a + pE(-1);
    return a;
}

int pT(){
    int a = pF();
    if(tryeatnxt('*'))
	return a * pT();
    return a;
}

int pF(){
    if(tryeatnxt('-'))
	return -pF();
    if(tryeatnxt('(')){
	int x = pE();
	eatnxt(')');
	return x;
    }
    int l=cur;

    while(cur!=n.size()&&(n[cur]=='0'||n[cur]=='1')){
	++cur;
    }
    //[l,cur)
    if(l==cur)
	ok = 0;

    if(cur-l>=2 && n[l]=='0')
	ok = 0;

    int x=0;
    for(int i=l;i<cur;++i)
	x=x*2+n[i]-'0';

    return x;
}


int main(){
    cin >> a;
    for(int i = 0; i < SZ(a); i++){
	if(islet(a[i]))v.PB(a[i]);
    }
    for(int i = 0; i < 8; i++){
	op.PB(x[i]);
    }

    sort(ALL(v));
    auto it = unique(ALL(v));
    v.resize(distance(v.begin(),it));

    //printf("sz %d\n",SZ(v));
    sort(ALL(op));
    fat[0]=1;
    for(int i = 1; i <= 8; i++)fat[i]=fat[i-1]*i;
    if(v.size()>8){
	printf("0\n");
    }
    else{
	int ans = 0;
	do{
	    ok=1, cur = 0;
	    n = a;
	    for(int i = 0; i < a.size(); i++){
		if(islet(a[i])){
		    int kk =lower_bound(ALL(v),a[i])-v.begin();
		    //printf("kk %d\n",kk);
		    n[i] = op[kk];
		}
	    }
	    //cout << n << endl;
	    pQ();
	    if(ok)ans++;
	}while(next_permutation(op.begin(),op.end()));
	printf("%d\n",ans/(fat[8-SZ(v)]));
    }


}
