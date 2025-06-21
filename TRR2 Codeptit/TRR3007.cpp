#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
const int maxN = 105;
int n,u,a[maxN][maxN];
set<int> adj[maxN];
bool visited[maxN];
vector<int> path(maxN,0);
vector<vector<int>> ans;

void Try(int v,int cnt){
    if(cnt==n && a[v][u-1]){
        path[++cnt] = u - 1;
        vector<int> tmp(path.begin(),path.begin()+cnt);
        ans.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        if(a[v][i] && !visited[i]){
            path[cnt] = i;
            visited[i] = true;
            Try(i,cnt+1);
            visited[i] = false;
        }
    }
}

void solve(){
    cin>>n>>u;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    visited[u-1] = 1;
    path[0] = u - 1;
    Try(u-1,1);
    for(auto it:ans){
        for(int x:it){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
    cout<<ans.size();
}
int main(){
    faster;
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    solve();
}
