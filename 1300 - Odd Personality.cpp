///17.8.2020
///Articulation Bridge + Connected Component

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1e9+7
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              10005
int t;
bool vis[sz];
vector< int >adj[sz];
int cost[sz],d[sz],p[sz],low[sz];
map< pair< int , int >, int  >badlinks;

int bfs(int s){

    queue< int > q;
    q.push(s);
    vis[s]=1;
    cost[s]=0;
    int nodes=0;
    bool ok=false;
    while(!q.empty()){
       int u=q.front();
       q.pop();
       nodes++;
       for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i];
            if(badlinks[{u,v}]==1)
                continue;
            if(vis[v]==0){
                cost[v]=cost[u]+1;
                vis[v]=1;
                q.push(v);
            }
            else{
                if((cost[u]+cost[v])%2==0){
                    ok=true;
                }
            }
       }
    }
    if(ok)return nodes;
    return 0;
}

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
                badlinks[{u,v}]=1;
                badlinks[{v,u}]=1;
            }
        }
        else if(v!=p[u]){
            low[u]=min(low[u],d[v]);
        }
    }
}

int solve(int n){

    ///mark bridges
    for(int i=0; i<n; i++){
        if(vis[i]==0){
            t=0;
            dfs(i);
        }
    }
    ///now we need to consider those components that have an odd cycle
    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++){
        if(vis[i]==0){
           cnt+=bfs(i);
        }
    }
    return cnt;
}

void reset(int n){
    badlinks.clear();
    for(int i=0; i<n; i++){
        adj[i].clear();
        p[i]=-1;
        cost[i]=d[i]=low[i]=vis[i]=0;
    }
}

int main(){
    Fast;///using Fast I/O
    int u,v,a,b,c, i,j,k, t,n,m,cs=1;

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

