#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int maxN = 105;
int t,n,u,degIn[maxN],degOut[maxN],a[maxN][maxN];
bool visited[maxN];
set<int> adj[maxN];
vector<int> adj2[maxN];
void dfs(int u){
    visited[u] = 1;
    for(int v:adj2[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]){
                degOut[i]++;
                degIn[j]++;
                adj[i].insert(j);
                adj2[i].push_back(j);
                adj2[j].push_back(i);
            }
        }
    }
}
void checkEuler(){
    cin>>n;
    init();
    dfs(1);
    int d1=0,d2=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<0;
            return;
        }
        if(abs(degIn[i] - degOut[i]) > 1){
            cout<<0;
            return;
        }
        if(degOut[i] - degIn[i] == 1) d1++;
        if(degIn[i] - degOut[i] == 1) d2++;
    }
    if(d1==0 && d2==0){
        cout<<1;
    }
    else if(d1==1 && d2==1){
        cout<<2;
    }
    else{
        cout<<0;
    }
}
void Euler(){
    cin>>n>>u;
    init();
    vector<int> CE;
    stack<int> st;
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        if(adj[v].size()){
            int x = *adj[v].begin();
            st.push(x);
            adj[v].erase(x);
        }
        else{
            st.pop();
            CE.push_back(v);
        }
    }
    reverse(CE.begin(),CE.end());
    for(int x:CE){
        cout<<x<<" ";
    }
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
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    solve();
}
