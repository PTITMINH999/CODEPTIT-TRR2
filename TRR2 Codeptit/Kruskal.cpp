#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
struct edge{
    int u,v,id;
    int w;
};
int n,m;
vector<edge> canh;
int parent[101],sz[101];
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}
bool Union(int a,int b){
    a=find(a); b=find(b);
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
    return true;
}
void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,id,w; cin>>x>>y>>w;
        id = i;
        edge e{x,y,id,w};
        canh.push_back(e);
    }
}
bool cmp(edge a, edge b){
    if(a.w==b.w) return a.id < b.id;
    return a.w<b.w;
}
void kruskal(){
    vector<edge> mst;
    int d=0;
    sort(canh.begin(),canh.end(),cmp);
    for(int i=0;i<m;i++){
        if(mst.size()==n-1) break;
        edge e = canh[i];
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d+=e.w;
        }
    }
    if(mst.size()<n-1){
        cout<<0;
    }
    else{
        cout<<d<<endl;
        for(auto e:mst){
            cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;
        }
    }
}
void solve(){
    canh.clear();
    nhap();
    make_set();
    kruskal();
}
int main(){
    faster();
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}