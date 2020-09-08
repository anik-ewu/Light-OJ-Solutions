///17.8.2020
///Articulation Point

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              10005

int t;
bool vis[sz];
int point[sz];
vector < int > adj[sz];
int par[sz],d[sz],low[sz];

void dfs(int u){

    vis[u]=1;
    d[u]=low[u]=++t;
    int child;
    for(int i=0; i<adj[u].size(); i++){
        child++;
        int v=adj[u][i];
        if(vis[v]==0){
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(par[u]==0 and child>1){
                point[u]=1;
            }
            if(par[u]!=0 and low[v]>=d[u]){
                point[u]=1;
            }
        }
        else if(v!=par[u]){
            low[u]=min(low[u],d[v]);
        }
    }

}

void dfs2(int u){
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0 && v!=1){
            dfs2(v);
        }
    }
}

void reset(int n){

    for(int i=1; i<=n; i++){
        adj[i].clear();
        par[i]=vis[i]=d[i]=low[i]=point[i]=0;
    }
}

int solve(int n){
    t=0;
    dfs(1);
    int cnt=0;
    for(int i=1; i<=n; i++)
        cnt+=point[i];

    ///since there may be a cycle in the graph we may need to extract root from the point list
    memset(vis,0,sizeof(vis));
    int tree=0;
    for(int i=2; i<=n; i++){
        if(vis[i]==0){
            tree++;
            dfs2(i);
        }
    }
    if(tree<2 && point[1])cnt--;

    return cnt;
}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m,cs=1;

    cin>>t;
    while(t--){
        cin>>n>>m;
        reset(n);
        for(i=1; i<=m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout<<"Case "<<cs++<<": "<<solve(n)<<endl;
    }
    return 0;
}

