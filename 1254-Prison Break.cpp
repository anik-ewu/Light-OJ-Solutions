/*
Date: 26-April- 2021
Algo: Diajkstra
Idea: From each node go to it's child node with all possible fuel and in the queue the top node should be the one
      which has min cost and more fuel .
      hint: order of priority queue {-cost, fuel, node};
*/

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
const int N=105;

int n;
int arr[N];
int vis[N][N];
int dis[N][N];
vector< pair< int , int > > adj[N];

int diajkstra(int st, int ed, int cap){

    priority_queue< pair< int , pair< int , int > > > pq;
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            dis[i][j]=INT_MAX, vis[i][j]=false;

    pq.push({0, {0, st}});
    dis[st][0]=0;
    while(!pq.empty()){
        int u=pq.top().ss.ss;
        int cost=pq.top().ff*-1;
        int fuel=pq.top().ss.ff;
        pq.pop();

        if(vis[u][fuel])continue;
        vis[u][fuel]=true;
        if(u==ed)return cost;

        for(auto x: adj[u]){
            int v=x.ff;
            int w=x.ss;

            for(int i=w; i<=cap; i++){
                int need=0;
                if(fuel<i)
                    need=i-fuel;
                int y=cost+(need*arr[u]);
                if(dis[v][i-w]>y){
                    dis[v][i-w]=y;
                    pq.push({-y, {i-w, v}});
                }
            }
        }
    }
    return -1;
}

int main(){

    int T, a, b, w, m;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        cin>>n>>m;
        for(int i=0; i<n; i++)
            adj[i].clear();
        for(int i=0; i<n; i++)
            cin>>arr[i];
        for(int i=1; i<=m; i++){
            cin>>a>>b>>w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        int s,e,q,c;
        cout<<"Case "<<tc<<":"<<endl;
        cin>>q;
        while(q--){
            cin>>c>>s>>e;
            int ans=diajkstra(s, e, c);
            if(ans==-1){
                cout<<"impossible"<<endl;
            }
            else
                cout<<ans<<endl;
        }
    }

    return 0;
}
