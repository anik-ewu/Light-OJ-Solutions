///17.8.2020
///Articulation Bridge

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
int d[sz],p[sz],low[sz];
vector< pair< int , int > >links;

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
                int a=min(u,v);
                int b=max(u,v);
                links.push_back({a,b});
            }

        }
        else if(v!=p[u]){
            low[u]=min(low[u],d[v]);
        }
    }
}

void reset(int n){
    links.clear();
    for(int i=0; i<n; i++){
        adj[i].clear();
        p[i]=-1;
        d[i]=low[i]=vis[i]=0;
    }
}

void solve(int n){
    for(int i=0; i<n; i++){
        if(vis[i]==0){
            t=0;
            dfs(i);
        }
    }
   if(links.size())sort(links.begin(),links.end());

}

int main(){
    Fast;///using Fast I/O
    int u,v,a,b,c, i,j,k, t,n,m,cs=1;

    cin>>t;
    while(t--){
        cin>>n;
        reset(n);
        char ch;
        for(i=1; i<=n; i++){
            cin>>u>>ch>>k>>ch;
            for(j=1; j<=k; j++){
                cin>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        solve(n);
        cout<<"Case "<<cs++<<":"<<endl;
        cout<<links.size() <<" critical links"<<endl;
        for(int i=0; i<links.size(); i++){
            cout<<links[i].first<<" - "<<links[i].second<<endl;
        }
    }

    return 0;
}

