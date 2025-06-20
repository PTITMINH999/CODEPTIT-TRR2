#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,int> 
#define all(v) v.begin(),v.end()
const int maxN = 105;
int n,s,t;
vector<pii> adj[maxN];
int par[maxN],d[maxN];
void init(){
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x>0 && x<=50){
                adj[i].push_back({j,x});
            }
        }
    }
}
void path(){
    vector<int> res;
    int u = t;
    while(u!=s){
        res.push_back(u);
        u = par[u];
    }
    res.push_back(s);
    reverse(all(res));
    for(int r:res){
        cout<<r<<" ";
    }
}
void djsktra(){
    for(int i=0;i<=n;i++) d[i] = 1e9;
    d[s] = 0;
    priority_queue<pii,vector<pii>,greater<>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pii f = pq.top();
        pq.pop();
        int kc = f.first;
        int u = f.second;
        if(kc > d[u]) continue;
        for(auto it:adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                par[v] = u;
                pq.push({d[v],v});
            }
        }
    }
    if(d[t]!=1e9){
        cout<<d[t]<<endl;
        path();
    }
    else{
        cout<<0;
    }
}
void solve(){
    init();
    djsktra();
}
int main(){
    faster;
    freopen("DN.INP","r",stdin);
    freopen("DN.OUT","w",stdout);
    solve();
}