///1-4-2021
///Straight forward articulation point

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll                inf = 1e9;

#define all(x)          (x).begin(), (x).end()
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int sz=1e4+5;

int Time;
bool vis[sz];
set< int > st;
int dis[sz], low[sz];
vector< int > adj[sz];

void reset(int n){
    int Time=0;
    st.clear();
    for(int i=1; i<=n; i++){
        vis[i]=dis[i]=low[i]=0;
        adj[i].clear();
    }
}

int dfs(int u, int par){

    vis[u]=1;
    dis[u]=low[u]=++Time;
    int child=0;
    for(int v: adj[u]){
        if(!vis[v]){
            child++;
            dfs(v, u);
            low[u]=min(low[u], low[v]);

            if(par==0 and child>1)st.insert(u);
            else if(par!=0 and low[v]>=dis[u])st.insert(u);
        }
        else{
            if(v!=par)low[u]=min(low[u], dis[v]);
        }
    }
}


int main(){
    
    Fast;   
    //read(x); write(x);

    int t, n, m, a, b;
    cin>>t;
    for(int cs=1; cs<=t;  cs++){
        cin>>n>>m;
        reset(n);
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,  0);
        cout<<"Case "<<cs<<": "<<st.size()<<endl;
    }


    return 0;
}

