#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,pair<int,int>> 
const int maxN = 105;
int t,n,m,k,u,v,w;
vector<int> adj[maxN];
vector<pii> edges;
int degIn[maxN],degOut[maxN],c[maxN][maxN];
void solve(){
    cin>>t>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        degOut[u]++;
        degIn[v]++;
        c[u][v] = w;
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<degIn[i]<<' '<<degOut[i]<<'\n';
        }
    }
    else{
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) cout<<"0 ";
                else{
                    if(c[i][j]) cout<<c[i][j]<<" ";
                    else cout<<10000<<" ";
                }
            }
            cout<<endl;
        }
    }
}
int main(){
    faster;
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
    solve();
}