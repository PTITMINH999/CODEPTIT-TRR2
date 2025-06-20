#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const int maxN = 105;
int t,n,m,k;
vector<int> adj[maxN];
vector<pair<int,int>> edges;
int degIn[maxN],degOut[maxN];
void solve(){
     cin>>t>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int x; cin>>x;
            edges.push_back({i,x});
            degIn[x]++;
            degOut[i]++;
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<degIn[i]<<" "<<degOut[i]<<endl;
        }
    }
    else{
        m = edges.size();
        cout<<n<<" "<<m<<endl;
        int A[n+1][m+1]={0};
        sort(edges.begin(),edges.end());
        for(int i=0;i<m;i++){
            int u = edges[i].first;
            int v = edges[i].second;
            A[u][i+1] = 1;
            A[v][i+1] = -1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
}
int main(){
    faster;
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
    solve();
}