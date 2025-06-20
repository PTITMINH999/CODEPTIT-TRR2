#include <bits/stdc++.h>
using namespace std;
int t,n,u,v;
int a[102][102]={0};
int e [103];bool vs[103];
void dfs (int u) {
    vs[u]=false ;
    for (int i=1;i<=n;i++) {
        if (vs[i]==true ) {
            if (a[u][i]==1) {
                e[i]=u;
               dfs (i);
            }
        }
    }
}
void solve () {
    cin>>t>>n>>u>>v;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    if (t==1) {
        int count=0;
        for (int i=1;i<=n;i++) {
            if (a[u][i]==1 && a[i][v]==1) {
                count++;
            }
        }
        cout<<count<<endl;
    }
    else {
        vector<int> mp;
        for (int i=1;i<=n;i++) {
            vs[i]=true;
            e[i]=0;
        }
        dfs(u);
        if (vs[v]==false) { 
            int t=v;
            while (t!=0) {
                mp.push_back(t);
                t=e[t];
            }
            for (int i=mp.size()-1;i>=0;i--) {
                cout<<mp[i]<<" ";
            }
            cout<<endl;
        }
        else {
            cout<<"0"<<endl;
        }
    }
}

int main () {
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    solve();

}