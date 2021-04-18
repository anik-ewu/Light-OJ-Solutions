///12 April 2021
///Tags: BFS/DFS
///Notes: Since  it is a tree, we can use both bfs or dfs. We need to find two corner node and make two
///separate search from those corner nodes and save the cost to reach each nodes. Finally, for each nodes
///look for the max from first or second search.

#include<bits/stdc++.h>
using namespace std;

const int N = 3e4+5;

bool vis[N];
int dis1[N];
int dis2[N];
vector< int > adj[N];
vector< int > cost[N];

void reset(int n){

    for(int i=0; i<n; i++){
        adj[i].clear();
        cost[i].clear();
        vis[i]=dis1[i]=dis2[i]=0;
    }
}

void dfs(int u, int par){
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(v==par)continue;
        if(vis[v]==0){
            dis1[v]=dis1[u]+cost[u][i];
            dfs(v, u);
        }
    }
}

void dfs2(int u, int par){
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(v==par)continue;
        if(vis[v]==0){
            dis2[v]=dis2[u]+cost[u][i];
            dfs2(v, u);
        }
    }
}


int main(){

    freopen("in.txt", "r", stdin);

    int t , n, m, a, b, c;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n;
        reset(n);
        for(int i=1; i<n; i++){
            cin>>a>>b>>c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        int len=0;
        int root=0;
        dfs(0,-1);/// moving into a corner

        for(int i=0; i<n; i++){
            if(dis1[i]>len){
                len=dis1[i];
                root=i;
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(dis1, 0, sizeof(dis1));
        dfs(root,-1);/// finding diameter

        root=0;
        len=0;
        for(int i=0; i<n; i++){
            if(dis1[i]>len){
                len=dis1[i];
                root=i;
            }
        }

        memset(vis, 0, sizeof(vis));
        dfs2(root, -1);

        cout<<"Case "<<tc<<":"<<endl;
        for(int i=0; i<n; i++){
            cout<<max(dis1[i], dis2[i])<<endl;
        }
    }

    return 0;
}
