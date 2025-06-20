#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,pair<int,int>> 
const int maxN = 105;
int t,n,m,k;
vector<int> adj[maxN];
vector<pii> edges;
int degIn[maxN],degOut[maxN],c[maxN][maxN];
void solve(){
    cin>>t>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]!=0 && c[i][j]!=10000){
                degOut[i]++;
                degIn[j]++;
                edges.push_back({i,{j,c[i][j]}});
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<degIn[i]<<" "<<degOut[i]<<'\n';
        }
    }
    else{
        int m = edges.size();
        cout<<n<<" "<<m<<'\n';
        sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++){
            int u = edges[i].first;
            int v = edges[i].second.first;
            int w = edges[i].second.second;
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
}
int main(){
    faster;
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
    solve();
}