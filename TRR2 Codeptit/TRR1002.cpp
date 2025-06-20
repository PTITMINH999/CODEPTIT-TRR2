#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
int deg[maxN],a[maxN][maxN];
vector<int> adj[maxN];
int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin>>t;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]) deg[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(a[i][j]) adj[i].push_back(j);
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<deg[i]<<" ";
        }
    }
    else{
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            cout<<adj[i].size()<<" ";
            for(int x:adj[i]){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }
}
