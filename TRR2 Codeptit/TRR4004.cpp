#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,int> 
const int maxN = 105;
int n,s;
bool visited[maxN];
vector<pii> adj[maxN];
struct edge{
    int u,v,w;
};
void init(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x>0 && x<=50 && i<j){
                adj[i].push_back({j,x});
                adj[j].push_back({i,x});
            }
        }
    }
}
void Prim(int u){
    int d = 0;
    vector<edge> mst;
    visited[u] = 1;
    while(mst.size() != n-1){
        int min_w = 1e6+7;
        int x =-1,y =-1;
        for(int i=1;i<=n;i++){
            if(visited[i]){
                for(auto it:adj[i]){
                    if(!visited[it.first]){
                        if(it.second < min_w){
                            min_w = it.second;
                            y = it.first;
                            x = i;
                        }
                    }
                }
            }
        }
        if (x == -1 || y == -1) break;
        mst.push_back({x,y,min_w});
        visited[y] = 1;
        d += min_w;
    }
    if(mst.size() < n-1){
        cout<<0;
    }
    else{
        cout<<d<<endl;
        for(auto it:mst){
            if(it.u > it.v) swap(it.u,it.v);
            cout<<it.u<<' '<<it.v<<' '<<it.w<<endl;
        }
    }
}
void solve(){
    init();
    Prim(s);
}
int main(){
    faster;
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
    solve();
}