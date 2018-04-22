// Bill kondo eh o responsavel
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 10;

int N;
int V[MAX], T[MAX];
int C;

int main() {
    cin.sync_with_stdio(false);
    
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> T[i] >> V[i];
        }
        cin >> C;
        while (C--) {
            string cmp, func;
            int len;
            deque<pii> Q; // Jiang 
            
            cin >> cmp >> func >> len;
            ll sum = 0;
            multiset<int> S;
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                //printf("==> Analizing %d\n", T[i]);
                while (!Q.empty() && ((T[i] - Q.front().second) > len)) {
                    //printf("--> Erasing element of time %d from queue\n", Q.front().second);
                    sum -= Q.front().first;
                    S.erase(S.find(Q.front().first));
                    Q.pop_front();
                }
                
                
                if (!Q.empty()) {
                    if (func == "avg") {
                        ll avg = 1LL * (ll)(Q.size()) * (ll)(V[i]);
                        //printf("--> avg = %lf and V[%d] = %d\n", avg, i, V[i]);
                        if (cmp == "gt") {
                            if (avg > sum) cnt++;
                        }
                        else if (cmp == "lt") {
                            if (avg < sum) cnt++;
                        }
                    } else if (func == "max") {
                        int MX = *(--S.end());
                        if (cmp == "gt") {
                            if (V[i] > MX) cnt++;
                        } else if (cmp == "lt") {
                            if (V[i] < MX) cnt++;
                        }
                    } else if (func == "min") {
                        int MN = *(S.begin());
                        if (cmp == "gt") {
                            if (V[i] > MN) cnt++;
                        } else if (cmp == "lt") {
                            if (V[i] < MN) cnt++;
                        }                    
                    }
                }
                
                Q.push_back(pii(V[i], T[i]));
                S.insert(V[i]);
                sum += V[i];
            }
            
            cout << cnt << '\n';
        }
    }

    
    return 0;
}
