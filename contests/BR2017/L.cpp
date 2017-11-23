#include <bits/stdc++.h>
using namespace std;


vector <int> coordx;
vector <int> coordy;

int calc(int x, int y){
  return abs(coordx[x]-coordx[y]) + abs(coordy[x]-coordy[y]);
}


int main() {
  int n;
  scanf("%d", &n);

  int sum = 0;
  coordx.push_back(sum);
  for(int i = 0; i < n-1; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
    coordx.push_back(sum);
  }
  sum = 0;
  for(int i = 0; i < n - 1; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
    coordy.push_back(sum);
  }

  int q;
  scanf("%d", &q);

  vector <pair<int,int> > c1, c2;
  
  for (int i = 0; i < q; ++i) {
    int ans = 0;
    int ax, ay;
    scanf("%d%d", &ax, &ay);
    int v1 = lower_bound(coordy.begin(), coordy.end(), ay)-coordy.begin();
    if(v1-1>=0)c1.push_back(pair<int,int> (v1-1,ay - coordy[v1-1]) );
    else c1.push_back(pair<int,int> (v1,coordy[v1] - ay));
    

    int bx, by;
    scanf("%d%d", &bx, &by);
    int v2 = lower_bound(coordx.begin(), coordx.begin(), bx)-coordx.begin();
    if(v2-1>=0)c2.push_back(pair<int,int> (v2-1, bx - coordx[v2-1]));
    else c2.push_back(pair<int,int> (v2, coordx[v2] - bx));
    
    for(auto x: c1){
      for(auto y: c2){
	ans = max(ans,abs(coordx[y.first] - ax) + abs(coordy[x.first] - by) + x.second+y.second);
      }
    }
    
    printf("%d\n", ans);
    
  }


  
  
  

}
