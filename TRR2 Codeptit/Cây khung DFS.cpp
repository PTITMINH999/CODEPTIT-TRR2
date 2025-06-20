#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int n,m,u;
vector<int> a[1001];
bool check[1001];
vector<pair<int,int>>ans;
void dfs(int u){
    check[u]=true;
    for(int v:a[u]){
        if(!check[v]){
            ans.push_back({u,v});
            dfs(v);
        }
    }
}
int main(){
    faster();
    run(){
        cin>>n>>m>>u;
        memset(check,false,sizeof(check));
        for(int i=0;i<1001;i++) a[i].clear();
        ans.clear();
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(u);
        if(ans.size()==n-1){
            for(auto p:ans){
                cout<<p.first<<" "<<p.second<<endl;
            }
        }
        else cout<<"-1\n";
    }
}