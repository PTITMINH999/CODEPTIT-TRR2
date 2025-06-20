#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
int deg[maxN],a[maxN][maxN];
int main(){
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
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
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            cout<<deg[i]<<" ";
        }
    }
    else{
        cout<<n<<" "<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}
