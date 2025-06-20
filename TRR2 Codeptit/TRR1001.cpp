#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
const int maxN = 105;
int t,n,a[maxN][maxN],deg[maxN];
vector<pii> edge;
void solve(){
    cin>>t>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(i<j && a[i][j]==1){
                deg[i]++;
                deg[j]++;
                edge.push_back({i,j});
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<deg[i]<<" ";
        }
    }
    else{
        sort(all(edge));
        cout<<n<<' '<<edge.size()<<endl;
        for(int i=0;i<edge.size();i++){
            cout<<edge[i].first<<" "<<edge[i].second<<endl;
        }
    }
}
int main(){
    faster;
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
    solve();
}