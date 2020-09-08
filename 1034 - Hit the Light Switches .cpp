///Find The Forests In the graph in topological order

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

bool vis[sz];
stack< int > st;
vector< int > adj[sz];
void dfs(int u){
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    st.push(u);
}


int solve(int n){

    for(int i=1; i<=n; i++){
        if(vis[i]==0)dfs(i);
    }
    int moves=0;
    memset(vis,0,sizeof(vis));
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(vis[u]){
            continue;
        }
        moves++;
        dfs(u);
    }
    return moves;
}
int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m, cs=1;
    cin>>t;

    while(t--){
        cin>>n>>m;
        for(i=1; i<=n; i++)adj[i].clear(),vis[i]=0;

        for(i=1; i<=m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
        }
        cout<<"Case "<<cs++<<": "<<solve(n)<<endl;
    }
    return 0;
}

