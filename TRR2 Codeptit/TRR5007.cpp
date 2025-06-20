#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,int> 
#define all(v) v.begin(),v.end()
const int maxN = 105;
int n,s,t;
struct edge{
    int x,y,w;
};
vector<edge> edges;
int par[maxN],d[maxN];
void init(){
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w; cin>>w;
            if(w!=0 && w!=10000){
                edge e{i,j,w};
                edges.push_back(e);
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
    cout<<d[t]<<endl;
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
}
void bellmanFord(){
    for(int i=0;i<=n;i++) d[i] = 1e9;
    d[s] = 0;
    par[s] = -1;
    for(int i=1;i<=n-1;i++){
        for(edge e:edges){
            int u = e.x, v = e.y, w = e.w;
            if(d[u] < 1e9){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    par[v] = u;
                }
            }
        }
    }

    for(int i=0;i<edges.size();i++){
        int u = edges[i].x;
        int v = edges[i].y;
        int w = edges[i].w;
        if(d[u] < 1e9){
            if(d[v] > d[u] + w){
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(d[t]!=1e9){
        path();
    }
    else{
        cout<<0;
    }
}
void solve(){
    init();
    bellmanFord();
}
int main(){
    faster;
    freopen("BN.INP","r",stdin);
    freopen("BN.OUT","w",stdout);
    solve();
}