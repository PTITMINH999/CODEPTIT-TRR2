#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
const int maxN = 105;
int t,n,u,v,par[maxN],a[maxN][maxN];
vector<int> adj[maxN];
bool visited[maxN];
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int v:adj[x]){
            if(!visited[v]){
                q.push(v);
                par[v]=x;
                visited[v] = 1;
            }
        }
    }
}
void path(){
    vector<int> res;
    int s = v;
    while(s!=u){
        res.push_back(s);
        s = par[s];
    }
    res.push_back(u);
    reverse(res.begin(),res.end());
    for(int x:res){
        cout<<x<<" ";
    }
}
void solve(){
    cin>>t>>n>>u>>v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]){
                adj[i].push_back(j);
            }
        }
    }
    if(t==1){
        int ans =0;
        for(int i=1;i<=n;i++){
            if(a[u][i]==1 && a[i][v]==1){
                ans++;
            }
        }
        cout<<ans;
    }
    else{
        bfs(u);
        if(visited[v]){
            path();
        }
        else{
            cout<<0;
        }
    }
}
int main(){
    faster;
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    solve();
}
