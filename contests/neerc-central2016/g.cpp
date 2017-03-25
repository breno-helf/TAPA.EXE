#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10467397;

bool solve (int &N)
{
    int cont = 0;
    
    for (int i = 2; (long long) (i) * (long long) (i) <= MAXN; ++i) 
    {
        int id = 0;
        
        while (N % i == 0)
        {
            N /= i;
            ++cont;   
            ++id;
        }
        
        if (id > 1)
            return false;
    }
   
    if (N > 1)
        ++cont;
    
    return (cont == 3);
}

int main ()
{
    cin.sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    int N;
    cin >> N;
   
    if (solve(N))
        cout << "YES\n";
    else
        cout << "NO\n";
        
    return 0;
}
