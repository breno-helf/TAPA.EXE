#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

int main(){
  long double a, b, c, r;
  long double p;		
  cin >> a >> b >> c >> r;
  p = (a+b+c)/2;
  long double area = sqrt(p) * sqrt(p-a) * sqrt(p-b) * sqrt(p-c);
  
  long double ri = (2.0 * area) / (a + b + c);
  long double ratio = r / ri;
  long double ai = a * ratio, bi = b * ratio , ci = c * ratio;

  long double pi = (ai + bi + ci) / 2;
  long double A2 =  sqrt(pi) * sqrt(pi - ai) * sqrt(pi - bi) * sqrt(pi - ci);

  long double calc = A2 - r * r * PI;
  // cout << "--- ";
  // cout << ri << ' ' << A2 << ' ' << calc << '\n';


  cout << fixed << setprecision(10) << (area - calc) / area << '\n';
  
  return 0;
}
