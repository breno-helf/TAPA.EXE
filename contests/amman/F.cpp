#include <bits/stdc++.h>

using namespace std;


char a[100010];
set <char> st;
map <char, int> mp;
int val[30];
char inv[30];

int main(){
    int t;
    scanf("%d",&t);
    for(int cas = 0; cas < t; cas++){
        scanf("%s",a);
        int n = strlen(a);
        int ok = 0;
        char fi='a',se='a';
        st.clear();
        mp.clear();
        for(int i = 0; i < n; i++){
            st.insert(a[i]);
        }
        int cnt = 1;
        for(auto it : st){
            inv[cnt] = it;
            mp[it]= cnt++;
        }
        for(int i = 0; i <= 26; i++){
            val[i]=0;
        }
        val[0]=1;
        for(int i = 0; i < n; i++){
            int at = mp[a[i]];
            //printf("%d\n",at);
            if(val[at-1]==1){
                val[at]=1;
            }
            else{
                for(int j = 1; j <= 26; j++){
                    if(val[j]==0){
                        fi =  a[i];
                        se =  inv[j];
                        ok=1;
                        //printf("%c %c\n",fi,se);
                        break;
                    }
                }
                break;
            }
            
        }
        if(ok==0)cout << a << endl;
        else{
            for(int i = 0; i < n; i++){
                if(a[i]==fi){
                    a[i]=se;
                }
                else if(a[i]==se){
                    a[i]=fi;
                }
            }
            cout << a << endl;
            
        }
    }

    
}
