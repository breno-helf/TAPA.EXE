//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;

int n;
double X, V;
double v[MAX], r[MAX], l[MAX];


int main() {
    scanf("%d %lf %lf", &n, &X, &V);
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf %lf", l + i, r + i, v + i);
        sum += (r[i] - l[i]) * v[i];
    }

    double K = sum / X;
    double sina = K / V;

    if (sina > 1 || sina < -1) {
        printf("Too hard\n");
        return 0;
    }
    
    double cosa = sqrt(1 - (K / V) * (K / V));
    double hV = cosa * V;
    double maxm = (2 * X) / V;
    double ans = 0;

    ans += l[1] / hV;

    
    for (int i = 1; i <= n; i++) {
        ans += (r[i] - l[i]) / hV;

        if (i == n) {
            ans += (X - r[i]) / hV;
        } else {
            ans += (l[i + 1] - r[i]) / hV;
        }
        
        if (ans > maxm) {
            printf("Too hard\n");
            return 0;
        }
    }

    printf("%.3lf\n", ans);
}


