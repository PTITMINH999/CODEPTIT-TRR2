#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
const int maxN =105;
int t,n,m,s;
bool visited[maxN];
set<int> adj[maxN];
void dfs(int u){
    visited[u] = 1;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
void checkEuler(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    if(cnt==1){
        int odd = 0;
        for(int i=1;i<=n;i++){
            if(adj[i].size() & 1) odd++;
        }
        if(odd) cout<<2;
        else cout<<1;
    }
    else cout<<0;
}
void Euler(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> CE;
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int v = st.top();
        if(adj[v].size()){
            int x = *adj[v].begin();
            st.push(x);
            adj[x].erase(v);
            adj[v].erase(x);
        }
        else{
            st.pop();
            CE.push_back(v);
        }
    }
    reverse(CE.begin(),CE.end());
    for(int x:CE) cout<<x<<" ";
}
void solve(){
    cin>>t;
    if(t==1){
        checkEuler();
    }
    else{
        Euler();
    }
}
int main(){
    faster;
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);
    solve();
}