/*
Date: 27 April 2021
Algo: Dijkstra
Idea: Just simply run Bellman ford algorithm to calculate the cost and to check the reachability
      run another DFS. If the [cost>=3 and possible to reach and cost<MX] print cost or print ?.
*/

#include<bits/stdc++.h>
using namespace std;

const int N=210;
int arr[N];
bool vis[N];
int cost[N];
vector< pair< int , int > > adj[N];


int cube(int val){
    return (val*val*val);
}

void dfs(int u){
    vis[u]=1;
    for(auto x: adj[u]){
        int v=x.first;
        if(vis[v]==0)
            dfs(v);
    }
}

bool bellmanford(int n){

    for(int i=1; i<=n; i++)
        cost[i]=INT_MAX/3;

    cost[1]=0;
    for(int k=1; k<n; k++){
        for(int i=1; i<=n; i++){
            for(auto x: adj[i]){
                int v=x.first;
                int w=x.second;
                int y=w+cost[i];
                if(cost[v]>y){
                    cost[v]=y;
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(auto x: adj[i]){
            int v=x.first;
            int w=x.second;
            int y=w+cost[i];
            if(cost[v]>y){
                return true; ///cycle exists
            }
        }
    }
    return false;///no cycle
}

void init(int n){

    for(int i=1; i<=n; i++){
        vis[i]=0;
        adj[i].clear();
    }
}

int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, n, m, a, b, w;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n;
        init(n);

        for(int i=1; i<=n; i++)
            cin>>arr[i];

        cin>>m;
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            int x=cube(arr[b]-arr[a]);
            adj[a].push_back({b, x});
        }

        int des, q;
        cout<<"Case "<<tc<<":"<<endl;
        cin>>q;

        dfs(1); ///reachable or not
        bool cycle=bellmanford(n); ///to check negative cycle

        while(q--){
            cin>>des;
            if(vis[des]==true and cost[des]<INT_MAX/3 and cost[des]>2)
                cout<<cost[des]<<endl;
            else
                cout<<'?'<<endl;
        }
    }

    return 0;
}
