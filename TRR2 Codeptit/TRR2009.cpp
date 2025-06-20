#include <bits/stdc++.h>
using namespace std;

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set

#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

const int mod = 998244353;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

const int maxN = 105;
int degr[maxN] , degl[maxN] , a[maxN][maxN],b[maxN][maxN],n,m,k,u,v;
vector<int> adj[maxN];
bool visited[maxN],ok=0;
vector<set<int>> ans;
set<int> st;
void dfs(int u){
    visited[u] = 1;
    st.insert(u);
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        st.clear();
        if(!visited[i]){
            dfs(i);
            ans.pb(st);
        }
    }
    cout<<ans.size()<<endl;;
    for(int i=0;i<ans.size();i++){
        for(int j:ans[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    faster;
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout); 
    int t =1;
    //cin>>t;
    while(t--){
        solve();
    }
}