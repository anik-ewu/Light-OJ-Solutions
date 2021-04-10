///1-4-2021
///Articulation Bridge
/// Time complexity O(V+E)
///Notes: cosider disconnected graph

#include<bits/stdc++.h>
using namespace std;
#define SZ 10005

int Time;
vector<int> adj[SZ];
int vis[SZ],low[SZ],dis[SZ];
vector< pair< int, int > > bridge;

void dfs(int u, int par) {
    vis[u]=1;
    low[u]=dis[u]=++Time;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v]>dis[u]){
                int a=min(u, v);
                int b=max(u, v);
                bridge.push_back({a,b});
            }
        }else{
            if(v != par) low[u] = min(low[u], dis[v]);
        }
    }
}

void reset(int n){
    Time=0;
    bridge.clear();
    for(int i=0; i<n; i++){
        vis[i]=low[i]=dis[i]=0;
        adj[i].clear();
    }
}

int main(){

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    char ch;
    int t, n,m,a,b;
    cin>>t;
    for(int cs=1; cs<=t; cs++){
        cin>>n;
        reset(n);
        for(int i=0;i<n;i++){
            cin>>a>>ch>>m>>ch;
            for(int j=0; j<m; j++){
                cin>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
        for(int i=0; i<n; i++)if(!vis[i]){
            Time=0;
            dfs(i,-1);
        }

        cout<<"Case "<<cs<<":"<<endl;
        cout<<bridge.size()<<' '<<"critical links"<<endl;
        if(bridge.size())sort(bridge.begin(), bridge.end());
        for(auto i: bridge){
            cout<<i.first<<" - "<<i.second<<endl;
        }
    }
    return 0;
}



