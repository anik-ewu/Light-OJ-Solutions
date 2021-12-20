/*
Date: 27 April 2021
Algo: Bellman ford
Idea: https://tinyurl.com/4fmu6nr8
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000+5;
ll cost[N];
bool vis[N];
vector< pair< int , int > > adj_T[N];

void bellmanford(int n){

    for(int i=0; i<=n; i++)
        cost[i]=INT_MAX;

    cost[0]=0;
    for(int k=0; k<n; k++){
        for(int i=0; i<=n; i++){
            for(auto x: adj_T[i]){
                int v=x.first;
                ll w=x.second;
                ll y=w+cost[i];
                if(cost[v]>y){
                    cost[v]=y;
                }
            }
        }
    }
    ///marking those nodes which are in a negative cycle
    queue< int > q;
    for(int i=0; i<=n; i++){
        for(auto x: adj_T[i]){
            int v=x.first;
            ll w=x.second;
            ll y=w+cost[i];
            if(cost[v]>y){
                q.push(v);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(auto x: adj_T[u]){
            int v=x.first;
            if(vis[v]==0){
                q.push(v);
            }
        }
    }
}

int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, n, m, a, b, w;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>m;
        for(int i=0; i<=n; i++)
            adj_T[i].clear();

        for(int i=1; i<=m; i++){
            cin>>a>>b>>w;
            adj_T[b].push_back({a, w});
        }

        cout<<"Case "<<tc<<": ";

        bellmanford(n-1); ///to check negative cycle

        bool ok=false;
        for(int i=0; i<n; i++){
            if(vis[i]){
                if(ok)cout<<' ';
                cout<<i;
                ok=true;
            }
        }

        if(!ok){
                cout<<"impossible";
        }
        cout<<endl;

    }
    return 0;
}
