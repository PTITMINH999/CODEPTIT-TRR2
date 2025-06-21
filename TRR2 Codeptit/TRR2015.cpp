#include <bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int maxN = 105;
int n,x,a[maxN][maxN];
bool visited[maxN];
vector<int> adj[maxN],rev_adj[maxN],adj2[maxN];

void dfs(int u,vector<int> adj[]){
    visited[u] = 1;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v,adj);
        }
    }
}

bool LTManh(){
    memset(visited,false,sizeof(visited));
    dfs(1,adj);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            return false;
        }
    }
    memset(visited,false,sizeof(visited));
    dfs(1,rev_adj);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

bool LTYeu(){
    memset(visited,false,sizeof(visited));
    dfs(1,adj2);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(x==1){
                adj[i].push_back(j);
                rev_adj[j].push_back(i);
                adj2[i].push_back(j);
                adj2[j].push_back(i);
            } 
        }
    }
    if(LTManh()) cout<<1;
    else if(LTYeu()) cout<<2;
    else cout<<0;
}
int main() {
    faster;
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    solve();
}
