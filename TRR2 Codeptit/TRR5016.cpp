#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,int> 
#define all(v) v.begin(),v.end()
const int maxN = 105;
int n;
int a[maxN][maxN],par[maxN][maxN];
void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            par[i][j] = i;
        }
    }
}
void path(int s,int t){
    vector<int> res;
    int u = t;
    while(u!=s){
        res.push_back(u);
        u = par[s][u];
    }
    res.push_back(s);
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
}
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j && i!=k && j!=k && a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }
    int ans = 0,s = 0,t = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans < a[i][j] && a[i][j] != 10000){
                ans = a[i][j];
                s = i;
                t = j;
            }
        }
    } 
    cout<<s<<" "<<t<<" "<<ans<<endl;
    path(s,t);
}
void solve(){
    init();
    Floyd();
}
int main(){
    faster;
    // freopen("DN.INP","r",stdin);
    // freopen("DN.OUT","w",stdout);
    solve();
}