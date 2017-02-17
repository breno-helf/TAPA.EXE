//Euclides Extendido

ll xEuclid(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  ll xx, yy, d = xEuclid(b%a, a, xx, yy);
  x = yy-(b/a)*xx;
  y = xx;
  if (d < 0) {
    d = -d;
    x = -x;
    y = -y;
  }
  return d;
}
