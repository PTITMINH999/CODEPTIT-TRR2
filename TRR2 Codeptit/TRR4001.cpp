#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int,int>
const int maxN = 105;
int t,n,s,A[maxN][maxN];
bool visited[maxN];
vector<int> adj[maxN];
vector<pii> ans;
void dfs(int u){
    visited[u] = 1;
    for(int v:adj[u]){
        if(!visited[v]){
            ans.push_back({u,v});
            dfs(v);
        }
    }   
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int v:adj[x]){
            if(!visited[v]){
                ans.push_back({x,v});
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
void solve(){
    cin>>t>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A[i][j];
            if(A[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    if(t==1){
        dfs(s);
        if(ans.size()==n-1){
            cout<<ans.size()<<endl;
            for(pii p:ans){
                if(p.first > p.second){
                    swap(p.first,p.second);
                }
                cout<<p.first<<" "<<p.second<<endl;
            }
        }
        else cout<<0;
    }
    else{
        bfs(s);
        if(ans.size()==n-1){
            cout<<ans.size()<<endl;        
            for(pii p:ans){
                if(p.first > p.second){
                    swap(p.first,p.second);
                }
                cout<<p.first<<" "<<p.second<<endl;
            }
        }
        else cout<<0;
    }
}
int main(){
    faster;
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
    solve();
}
