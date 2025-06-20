#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
const int maxN = 105;
int n,m,u;
bool visited[maxN];
set<int> adj[maxN];
int path[maxN];
vector<vector<int>> ans;

void init(){
    cin>>n>>m>>u;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].insert(y);
    }
}

void Hamilton(int cnt,int v){
    visited[v] = 1;
    path[cnt] = v;
    if(cnt==n){
        if(adj[v].count(path[1])==1){
            path[++cnt] = path[1];
            vector<int> tmp(path+1, path+cnt+1);
            ans.push_back(tmp);
        }
        return;
    }

    for(int x:adj[v]){
        if(!visited[x]){
            Hamilton(cnt+1,x);
            visited[x] = 0;
        }
    }
    visited[v] = 0;
}

void solve(){
    init();
    Hamilton(1,u);
    for(auto it:ans){
        for(int i=0;i<it.size();i++){
            cout<<it[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<ans.size();
}
int main(){
    faster;
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    solve();
}