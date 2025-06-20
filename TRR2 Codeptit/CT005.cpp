#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
const int maxN = 105;
int n,m,u,a[maxN][maxN];
bool visited[maxN];
vector<int> path;
vector<vector<int>> ans;

void Try(int v,int cnt){
    if (cnt == n && a[v][u]) {
        path.push_back(u);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[v][i] && !visited[i]){
            visited[i] = 1;
            path.push_back(i);
            Try(i,cnt+1);
            path.pop_back();
            visited[i] = 0;
        }
    }
}
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = 0;
        }
    }
}
void solve(){
    cin>>n>>m>>u;
    init();
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y] = 1;
        a[y][x] = 1;    
    }
    path.push_back(u);
    visited[u] = 1;
    Try(u,1);
    cout<<ans.size()<<"\n";
    for(auto it:ans){
        for(int x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    faster;
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);
    solve();
}
