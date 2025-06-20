#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define pii pair<int,int>
const int maxN = 105;
int t,n,m;
int degIn[maxN],a[maxN][maxN],b[maxN][maxN];
vector<pii> edge;
void solve(){
    cin>>t>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            int u; cin>>u;
            degIn[i]++;
            a[i][u] = 1;
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<degIn[i]<<" ";
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i][j]==1){
                    edge.push_back({i,j});
                }
            }
        }
        sort(edge.begin(),edge.end());
        cout<<n<<" "<<edge.size()<<endl;
        for(int i=0;i<edge.size();i++){
            int u = edge[i].first;
            int v = edge[i].second;
            b[u][i+1] = 1;
            b[v][i+1] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=edge.size();j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    faster;
    // freopen("DT.INP","r",stdin);
    // freopen("DT.OUT","w",stdout);
    solve();
}