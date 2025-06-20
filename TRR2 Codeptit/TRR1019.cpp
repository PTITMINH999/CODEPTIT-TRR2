#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const int maxN = 105;
int t,n,m,k;
vector<int> adj[maxN];
int degIn[maxN],degOut[maxN];
void solve(){
    cin>>t>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        m+=k;
        for(int j=1;j<=k;j++){
            int x; cin>>x;
            adj[i].push_back(x);
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
        cout<<n<<" "<<m<<endl;
        for(int i=1;i<=n;i++){
            for(int j=0;j<adj[i].size();j++){
                cout<<i<<" "<<adj[i][j]<<endl;
            }
        }
    }
} 
int main(){
    faster;
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
    solve();
}