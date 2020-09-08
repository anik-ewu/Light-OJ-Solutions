///Date     : 18.8.2020
///Approach : Bridge Tree
///Idea     : Make a bridge tree of the graph and count the number of leaf on that tree | ans = (leaf/2)+(leaf%2)

#include<bits/stdc++.h>
using namespace std;
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sz              10005

int t;
bool vis[sz];
vector< int >adj[sz];
map < int , int > mp;
vector< pair< int , int > >links;
int Degree[sz],d[sz],p[sz],low[sz];
map< pair< int , int >, int  >bridge;

///DFS from finding bridges
void dfs(int u){
    vis[u]=1;
    d[u]=low[u]=++t;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            p[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>d[u]){
                bridge[{u,v}]=1;
                bridge[{v,u}]=1;
                links.push_back({u,v});///bridge
            }
        }
        else if(v!=p[u]){
            low[u]=min(low[u],d[v]);
        }
    }
}

///DFS for turning bridge less component into a single node
void dfs2(int u, int node){
    vis[u]=1;
    mp[u]=node;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(bridge[{u,v}])
            continue;
        if(vis[v]==0){
            dfs2(v,node);
        }
    }
}

int solve(int n){

    for(int i=0; i<n; i++){
        if(vis[i]==0){
            t=0;
            dfs(i);///save bridges
        }
    }

    int node=0;
    mp.clear();
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++){
        if(vis[i]==0){
            node++;
            dfs2(i,node);///Turn Component into a node
        }
    }
    ///Build Bridge Tree
    memset(Degree,0,sizeof(Degree));
    for(int i=0; i<links.size(); i++){
        int a=mp[links[i].first];
        int b=mp[links[i].second];
        Degree[a]++;
        Degree[b]++;
    }
    ///Count The Number Of Leaf Nodes
    int Leaf=0;
    for(int i=1; i<=node; i++){
        if(Degree[i]==1)Leaf++;
    }
    return (Leaf+1)/2;
}

void reset(int n){
    links.clear();
    bridge.clear();
    for(int i=0; i<n; i++){
        p[i]=-1;
        adj[i].clear();
        d[i]=low[i]=vis[i]=0;
    }
}

int main(){
    Fast;///using Fast I/O
    int u,v,i,t,n,m,cs=1;

    cin>>t;
    while(t--){
        cin>>n>>m;
        reset(n);
        for(i=1; i<=m; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<"Case "<<cs++<<": "<<solve(n)<<endl;
    }
    return 0;
}

