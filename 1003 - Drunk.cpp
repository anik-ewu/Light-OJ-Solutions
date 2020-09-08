///Find Cycle : Find back edge using dfs

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

bool cycle;
int vis[sz];
stack< int > st;
vector< int > adj[sz];
map< string, int > mp;

void dfs(int u){
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
        else if(vis[v]==1){
            cycle=true;
        }
    }
    vis[u]=2;
}

void solve(int n, int cs){

    cycle=false;
    for(int i=1; i<=n; i++){
        if(vis[i]==0)dfs(i);
    }
    if(cycle)cout<<"Case "<<cs<<": No"<<endl;
    if(!cycle)cout<<"Case "<<cs<<": Yes"<<endl;
}

int main(){
    Fast;///using Fast I/O

    string s,p;
    int a,b,c, i,j,k, t,n,m, cs=1;
    cin>>t;
    while(t--){

        mp.clear();
        cycle=false;
        cin>>n;
        for(i=1; i<=n; i++)adj[i].clear(),vis[i]=0;
        int cnt=1;
        for(i=1; i<=n; i++){
            cin>>s>>p;
            if(mp[s]==0)mp[s]=cnt++;
            if(mp[p]==0)mp[p]=cnt++;
            a=mp[s];b=mp[p];
            adj[a].push_back(b);
        }
        solve(cnt-1,cs++);
    }
    return 0;
}


