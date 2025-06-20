#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
const int maxN = 105;
int t,n,s,k,degIn[maxN],degOut[maxN];
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
void init(){
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>s;
            adj[i].insert(s);
            adj[s].insert(i);
            degOut[i]++;
            degIn[s]++;
        }
    }
}
void init1(){
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int u; cin>>u;
            adj[i].insert(u);
        }
    }
}
void checkEuler(){
    cin>>n;
    init();
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    if(cnt==1){
        int d=0;
        for(int i=1;i<=n;i++){
            if(degIn[i] != degOut[i]){
                if(abs(degIn[i]-degOut[i]) > 1){
                    cout<<0;
                    break;
                }
                else{
                    d++;
                }
            }
        }
        if(d==0) cout<<1;
        else if(d<=2) cout<<2;
        else cout<<0;
    }
    else cout<<0;
}
void Euler(){
    cin>>n>>s;
    init1();
    vector<int> CE;
    stack<int> st;
    st.push(s);
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