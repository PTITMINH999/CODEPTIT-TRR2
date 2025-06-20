#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int n, a[MAX][MAX];
bool visited[MAX];
vector<int> adj[MAX];      
vector<int> rev_adj[MAX];   
vector<int> undirected[MAX]; 

void dfs(int u, vector<int> g[]) {
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v]) dfs(v, g);
}

bool isStronglyConnected() {
    memset(visited, false, sizeof visited);
    dfs(1, adj);
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) return false;
    memset(visited, false, sizeof visited);
    dfs(1, rev_adj);
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) return false;

    return true;
}

bool isWeaklyConnected() {
    memset(visited, false, sizeof visited);
    dfs(1, undirected);
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) return false;
    return true;
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                adj[i].push_back(j);        
                rev_adj[j].push_back(i);     
                undirected[i].push_back(j);  
                undirected[j].push_back(i);  
            }
        }

    if (isStronglyConnected()) cout << 1;
    else if (isWeaklyConnected()) cout << 2;
    else cout << 0;

    return 0;
}