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
int degr[maxN],degl[maxN],a[maxN][maxN],n,m;
vector<int> adj[maxN];
vector<pii> edge;
void solve(){
    int k;
    cin>>k>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]){
                degr[i]++;
                degl[j]++;
                edge.pb({i,j});
            }
        }
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            cout<<degl[i]<<" "<<degr[i]<<endl;
        }
    }
    else{
        cout<<n<<" "<<edge.size()<<endl;
        for(auto e:edge){
            cout<<e.fi<<" "<<e.se<<endl;
        }
    }
}
int main(){
    faster;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t =1;
    //cin>>t;
    while(t--){
        solve();
    }
}