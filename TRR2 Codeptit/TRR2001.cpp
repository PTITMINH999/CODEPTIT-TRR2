#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL); 
const int maxN = 105;
int t,n,u,v;
int a[maxN][maxN], par[maxN];
vector<int> adj[maxN];
bool visited[maxN];
void dfs(int u){
    visited[u] = 1;
    for(int v:adj[u]){
        if(!visited[v]){
            par[v] = u;
            dfs(v);
        }
    }
}
void path(int u,int v){
    vector<int> res;
    int s = v;
    while(s!=u){
       res.push_back(s); 
       s = par[s];
    }
    res.push_back(u);
    for(int i = res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
}

void solve(){
    cin>>t>>n>>u>>v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]) adj[i].push_back(j);
        }
    }

    if(t==1){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(a[u][i]==1 && a[i][v]==1){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    else{
        dfs(u);
        if(visited[v]){
            path(u,v);
        }
        else{
            cout<<0;
        }
    }
}
int main () {
    faster;
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    solve();
}
