#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int n,m,u;
vector<int> a[1001];
bool check[1001];
vector<pair<int,int>>ans;
void bfs(int u){
    queue<int> q;
    check[u]=true;
    q.push(u);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int v:a[x]){
            if(!check[v]){
                ans.push_back({x,v});
                check[v]=true;
                q.push(v);
            }
        }
    }
}
int main(){
    faster();
    run(){
        for(int i=0;i<1001;i++) a[i].clear();
        ans.clear();
        memset(check,false,sizeof(check));
        cin>>n>>m>>u;
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        bfs(u);
        if(ans.size()==n-1){
            for(auto p:ans) 
                cout<<p.first<<" "<<p.second<<endl;
        }
        else cout<<-1<<endl;
    }
}